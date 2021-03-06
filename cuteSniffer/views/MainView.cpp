#include <iostream>
#include <QtQml>
#include <QQuickWindow>
#include <QQmlComponent>
#include <time.h>
#include "MainView.hh"
#include "PcapHandler.hh"
#include "Ethernet.hh"
#include "FilterData.hh"
#include "ARP.hpp"

MainView::MainView(QQmlApplicationEngine *engineApp) :  engineApp(engineApp),
    interface("eth0"), mac("00:0c:29:a2:74:01") {
    this->clientHandler.setUserMac(mac);
    initView();
    connect(&timerSocket, SIGNAL(timeout()), this, SLOT(catchPacket()));
}

MainView::~MainView() {

}

void MainView::initView() {
    qmlRegisterType<EthernetDisplay>("__data_element__", 1, 0, "EthernetDisplay");
    qmlRegisterType<Client>("__data_element__", 1, 0, "Client");
    qmlRegisterType<FilterData>("__data_element__", 1, 0, "FilterData");
    engineApp->rootContext()->setContextProperty("__root__", this);
    engineApp->rootContext()->setContextProperty("__clientHandler__", &clientHandler);
    engineApp->rootContext()->setContextProperty("__filters__", &(FilterData::getInstance()));
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

int MainView::getCurrentRow() const {
    return packets.size();
}

void MainView::catchPacket() {
    Ethernet *packet = RawSocket::getInstance().getPacket();
    if (packet == NULL)
        return;
    if (!FilterData::getInstance().validate(packet))
        return;
    this->clientHandler.addClient(packet);
    packetsData.push_back(packet);
    packets.push_back(new EthernetDisplay(packet));
    emit this->packetsChanged();
    emit this->currentRowChanged();
}

void MainView::displayUsers() {
    QQmlComponent component(engineApp);
    component.loadUrl(QUrl(QStringLiteral("qrc:/views/users.qml")));
    if (component.isReady())
        component.create();
}

void MainView::rowDoubleClick(int row) {
    QQmlEngine *engine = new QQmlEngine;
    QQmlComponent component(engine);
    engine->rootContext()->setContextProperty("__packet__", new EthernetDisplay(packets.at(row)->getPacket()));
    component.loadUrl(QUrl(QStringLiteral("qrc:/views/ethernet.qml")));
    if (component.isReady())
        component.create();
}

void MainView::newPacket() {
    QQmlEngine *engine = new QQmlEngine;
    QQmlComponent component(engine);
    engine->rootContext()->setContextProperty("__packet__", new EthernetDisplay());
    component.loadUrl(QUrl(QStringLiteral("qrc:/views/ethernet.qml")));
    if (component.isReady())
        component.create();
}

void MainView::runCapture() {
    if (!timerSocket.isActive() && !RawSocket::getInstance().runPromiscious(interface.toStdString().c_str())) {
        timerSocket.start(1);
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
    QQmlComponent component(engineApp);
    component.loadUrl(QUrl(QStringLiteral("qrc:/views/savePcap.qml")));
    if (component.isReady())
        component.create();
}

void MainView::openCapture(){
    QQmlComponent component(engineApp);
    component.loadUrl(QUrl(QStringLiteral("qrc:/views/openPcap.qml")));
    if (component.isReady())
        component.create();
}

void MainView::openFileSelect() {
    packets.clear();
    packetsData.clear();
    try {
        PcapHandler pcap(this->openFile.toStdString());
        packetsData = pcap.getPackets();
        for (Ethernet *pkt : packetsData)
            packets.push_back(new EthernetDisplay(pkt));
        emit packetsChanged();
    } catch (std::exception e) {
        std::cerr << "Impossible d'ouvrir le fichier : "<< e.what() << std::endl;
    }
}

void MainView::saveFileSelect() {
    try {
        PcapHandler pcap(this->saveFile.toStdString());
        pcap.writeFile(packetsData);
    } catch (std::exception e) {
        std::cerr << "Impossible de sauvegarder le fichier : "<< e.what() << std::endl;
    }
}

void MainView::deleteCapture() {
    packets.clear();
    packetsData.clear();
    emit this->packetsChanged();
}

QQmlListProperty<EthernetDisplay> MainView::getPackets() {
    return QQmlListProperty<EthernetDisplay>(this, packets);
}

QString MainView::getInterface() const {
    return this->interface;
}

void MainView::setInterface(QString value) {
    this->interface = value;
    emit interfaceChanged();
}

QString MainView::getMac() const {
    return this->mac;
}

void MainView::setMac(QString value) {
    this->mac = value;
    this->clientHandler.setUserMac(mac);
    emit macChanged();
}

ClientHandler MainView::getClientHandler() const {
    return this->clientHandler;
}
