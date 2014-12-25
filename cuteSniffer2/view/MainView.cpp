#include <iostream>
#include <QtQml>
#include "MainView.hh"
#include "Ethernet.hh"
#include "ARP.hpp"

MainView::MainView(QQmlApplicationEngine *engine) : engine(engine) {
    initView();
    initNetwork();
    //initData();
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

void MainView::initData() {
    // ###########################################
    // Simple Ethernet
    // ###########################################
    Ethernet *pqt = new Ethernet();
    pqt->setEther_dhost("00:01:02:03:04:05");
    pqt->setEther_shost("99:22:33:55:af:d1");
    pqt->setEther_type('a');

    // ###########################################
    // Simple ARP (Hérité de Ethernet)
    // ###########################################
    ARP<Ethernet> *pqt2 = new ARP<Ethernet>();
    pqt2->setEther_dhost("00:09:17:ee:24:fa");
    pqt2->setSpa("192.168.0.17");
    pqt2->setTpa("25.182.17.28");

    // ###########################################
    // Ethernet transformé en ARP
    // ###########################################
    Ethernet *pqt3 = new Ethernet();
    pqt3->setEther_dhost("a1:b2:c3:d4:e5:f6");
    pqt3->setEther_shost("ff:ee:dd:cc:bb:aa");
    pqt3->setEther_type('z');

    ARP<Ethernet> *pqt4 = new ARP<Ethernet>(*pqt3);
    pqt4->setSpa("192.168.0.14");

    // ADD TO DATA
    packets.push_back(new EthernetDisplay(pqt));
    packets.push_back(new EthernetDisplay(pqt2));
    packets.push_back(new EthernetDisplay(pqt3));
    packets.push_back(new EthernetDisplay(pqt4));
    emit this->packetsChanged();
}

void MainView::catchPacket() {
    Ethernet *packet = socket.getPacket();
    if (packet == NULL)
        return;
    packets.push_back(new EthernetDisplay(packet));
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

