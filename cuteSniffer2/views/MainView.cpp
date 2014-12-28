#include <iostream>
#include <QtQml>
#include <QQuickWindow>
#include <QQmlComponent>
#include "MainView.hh"
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

void MainView::catchPacket() {
    Ethernet *packet = RawSocket::getInstance().getPacket();
    if (packet == NULL)
        return;
    packets.push_back(new EthernetDisplay(packet));
    if (packets.count() > 15)
    	packets.removeFirst();
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
        std::cout << "START CAPTURE" << std::endl;
        timerSocket.start(200);
    }
    else
        emit promisciousError();
}

void MainView::stopCapture() {
    if (timerSocket.isActive()) {
        timerSocket.stop();
        RawSocket::getInstance().stopPromiscious();
        std::cout << "STOP CAPTURE" << std::endl;
    }
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

