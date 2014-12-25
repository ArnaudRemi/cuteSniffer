#include <iostream>
#include <QtQml>
#include "MainView.hh"
#include "Ethernet.hh"
#include "ARP.hpp"

MainView::MainView(QQmlApplicationEngine *engine) : engine(engine), interface("eth0") {
    initView();
    initNetwork();
}

MainView::~MainView() {

}

void MainView::initView() {
    qmlRegisterType<EthernetDisplay>("__data_element__", 1, 0, "EthernetDisplay");
    engine->rootContext()->setContextProperty("__root__", this);
    engine->load(QUrl::fromLocalFile("view/main.qml"));
}

void MainView::initNetwork() {
    socket.goPromiscious("eth0");
    connect(&timerSocket, SIGNAL(timeout()), this, SLOT(catchPacket()));
}

void MainView::catchPacket() {
    Ethernet *packet = socket.getPacket();
    if (packet == NULL)
        return;
    packets.push_back(new EthernetDisplay(packet));
    if (packets.count() > 15)
    	packets.removeFirst();
    emit this->packetsChanged();
}

void MainView::rowDoubleClick(int row) {
    std::cout << "ROW : " << row << std::endl;
}

void MainView::runCapture() {
    if (!timerSocket.isActive()) {
        std::cout << "RUN CAPTURE" << std::endl;
        timerSocket.start(200);
    }
}

void MainView::stopCapture() {
    if (timerSocket.isActive()) {
        std::cout << "STOP CAPTURE" << std::endl;
        timerSocket.stop();
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

