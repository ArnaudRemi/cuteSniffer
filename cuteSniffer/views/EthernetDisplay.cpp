#include "EthernetDisplay.hh"
#include "RawSocket.hh"

EthernetDisplay::EthernetDisplay() {

}

EthernetDisplay::EthernetDisplay(Ethernet *packet) : packet(packet) {
    packet->actualizeBuffer();
    shost = packet->getEther_shost().c_str();
    dhost = packet->getEther_dhost().c_str();
    src = packet->getSource().c_str();
    dst = packet->getDestination().c_str();
    type = packet->getEther_typeString().c_str();
    dotData = Utils::convertBrutDataToDotString(packet->getBuffer(), packet->getBufferSize()).c_str();
    data = Utils::convertBrutDataToString(packet->getBuffer(), packet->getBufferSize()).c_str();
}

EthernetDisplay::~EthernetDisplay() {

}

QString EthernetDisplay::getDhost() const {
    return this->dhost;
}
QString EthernetDisplay::getShost() const {
    return this->shost;
}
QString EthernetDisplay::getType() const {
    return this->type;
}
QString EthernetDisplay::getData() const {
    return this->data;
}
QString EthernetDisplay::getDotData() const {
    return this->dotData;
}

QString EthernetDisplay::getSrc() const {
    return src;
}
QString EthernetDisplay::getDst() const {
    return dst;
}
void EthernetDisplay::setDhost(QString dhost) {
    this->dhost = dhost;
}

void EthernetDisplay::setShost(QString shost) {
    this->shost = shost;
}

void EthernetDisplay::setType(QString type) {
    this->type = type;
}

void EthernetDisplay::setData(QString data) {
    this->data = data;
}

void EthernetDisplay::setDotData(QString data) {
    this->dotData = data;
}

Ethernet *EthernetDisplay::getPacket() const {
    return this->packet;
}

void EthernetDisplay::actualizePacket() {
    try {
        int len = 0;
        unsigned char *buffer = Utils::convertStringToBrutData(this->data.toStdString(), &len);
        Ethernet *newPacket = new Ethernet(buffer, len);
        newPacket->setEther_dhost(this->dhost.toStdString());
        newPacket->setEther_shost(this->shost.toStdString());
        newPacket->setEther_type(this->getType().toStdString());
        packet = newPacket;
    } catch (std::exception) {
        std::cerr << "Erreur dans la formation du paquet" << std::endl;
    }
}

void EthernetDisplay::sendPacket() {
    this->actualizePacket();
    RawSocket::getInstance().sendPacket(packet);
}
