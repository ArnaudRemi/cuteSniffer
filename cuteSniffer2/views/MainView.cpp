#include <iostream>
#include <QtQml>
#include <QQuickWindow>
#include <QQmlComponent>
#include <time.h>
#include "MainView.hh"
#include "PcapHandler.hh"
#include "Ethernet.hh"
#include "ARP.hpp"

MainView::MainView(QQmlApplicationEngine *engineApp) : engineApp(engineApp), interface("eth0") {
    initView();
    connect(&timerSocket, SIGNAL(timeout()), this, SLOT(catchPacket()));
}

MainView::~MainView() {

}

void MainView::initView() {
    qmlRegisterType<EthernetDisplay>("__data_element__", 1, 0, "EthernetDisplay");
    engineApp->rootContext()->setContextProperty("__root__", this);
    QQmlComponent component(engineApp);
    component.loadUrl(QUrl(QStringLiteral("qrc:/views/main.qml")));
    if (component.isReady())
        component.create();
}

void MainView::setOpenFile(QString const &openFile) {
    this->openFile = openFile;
    emit this->openFileChanged();
}

QString MainView::getOpenFile() const {
    return openFile;
}

void MainView::setSaveFile(QString const &saveFile) {
    this->saveFile = saveFile;
    emit this->saveFileChanged();
}

QString MainView::getSaveFile() const {
    return saveFile;
}

void MainView::catchPacket() {
    Ethernet *packet = RawSocket::getInstance().getPacket();
    if (packet == NULL)
        return;

    /*    if (!this->filters.isEmpty()) {
        for (int i = 0; i < this->filters.size(); ++i) {
            if (this->filters[i]->isActive() && !this->filters[i]->isValid(packet))
                return;
        }
    } */
    packetsData.push_back(packet);
    packets.push_back(new EthernetDisplay(packet));
    emit this->packetsChanged();
}

void MainView::displayUsers() {
    QQmlEngine *engine = new QQmlEngine;
    QQmlComponent component(engine);
    component.loadUrl(QUrl(QStringLiteral("qrc:/views/users.qml")));
    if (component.isReady())
        component.create();
}

void MainView::rowDoubleClick(int row) {
    QQmlEngine *engine = new QQmlEngine;
    QQmlComponent component(engine);
    engine->rootContext()->setContextProperty("__packet__", packets.at(row));
    component.loadUrl(QUrl(QStringLiteral("qrc:/views/ethernet.qml")));
    if (component.isReady())
        component.create();
    std::cout << "ROW : " << row << std::endl;
}

void MainView::runCapture() {
    if (!timerSocket.isActive() && !RawSocket::getInstance().runPromiscious(interface.toStdString().c_str())) {
        timerSocket.start(200);
    }
    else
        emit promisciousError();
}

void MainView::stopCapture() {
    if (timerSocket.isActive()) {
        timerSocket.stop();
        RawSocket::getInstance().stopPromiscious();
    }
}

void MainView::saveCapture() {
    this->saveFile = "/tmp/pcapsave_";
    this->saveFile += std::to_string((long int)time(NULL)).c_str();
    QQmlEngine *engine = new QQmlEngine;
    QQmlComponent component(engine);
    engine->rootContext()->setContextProperty("__root__", this);
    component.loadUrl(QUrl(QStringLiteral("qrc:/views/savePcap.qml")));
    if (component.isReady())
        component.create();
}

void MainView::openCapture(){
    QQmlEngine *engine = new QQmlEngine;
    QQmlComponent component(engine);
    engine->rootContext()->setContextProperty("__root__", this);
    component.loadUrl(QUrl(QStringLiteral("qrc:/views/openPcap.qml")));
    if (component.isReady())
        component.create();
}

void MainView::openFileSelect() {
    std::cout << "openFile : " << this->openFile.toStdString() << std::endl;
    packets.clear();
    packetsData.clear();
    try {
        PcapHandler pcap(this->openFile.toStdString());
        packetsData = pcap.getPackets();
        for (Ethernet *pkt : packetsData)
            packets.push_back(new EthernetDisplay(pkt));
        emit packetsChanged();
    } catch (std::exception e) {
        std::cout << "Impossible d'ouvrir le fichier : "<< e.what() << std::endl;
    }
}

void MainView::saveFileSelect() {
    std::cout << "saveFile : " << this->saveFile.toStdString() << std::endl;
    try {
        PcapHandler pcap(this->saveFile.toStdString());
        pcap.writeFile(packetsData);
    } catch (std::exception e) {
        std::cout << "Impossible de sauvegarder le fichier : "<< e.what() << std::endl;
    }
}

void MainView::deleteCapture() {
    packets.clear();
    packetsData.clear();
    emit this->packetsChanged();
    std::cout << "deleteCapture" << std::endl;
}

QQmlListProperty<EthernetDisplay> MainView::getPackets() {
    return QQmlListProperty<EthernetDisplay>(this, packets);
}

QString MainView::getInterface() const {
    return this->interface;
}

void MainView::setInterface(QString value) {
    this->interface = value;
    std::cout << "Interface : " << value.toStdString() << std::endl;
}

//void MainView::addStringFilter() {this->addFilter(new StringFilter);}

/*void MainView::addFilter(Filter *filter) {
    filter->getWidget()->startConfig();
    this->filters.append(filter);
}*/

