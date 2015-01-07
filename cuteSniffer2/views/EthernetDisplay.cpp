#include "EthernetDisplay.hh"
#include "RawSocket.hh"

EthernetDisplay::EthernetDisplay() {

}

EthernetDisplay::EthernetDisplay(Ethernet *packet) : packet(packet),
                                                     shost(packet->getEther_shost().c_str()),
                                                     dhost(packet->getEther_dhost().c_str()),
                                                     type(packet->getEther_typeString().c_str()),
                                                     data(packet->getPayload().c_str()) {

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

Ethernet *EthernetDisplay::getPacket() const {
    return this->packet;
}

void EthernetDisplay::actualizePacket() {
    try {
    Ethernet *newPacket = new Ethernet(*this->packet);
    newPacket->setEther_dhost(this->dhost.toStdString());
    newPacket->setEther_shost(this->shost.toStdString());
    //newPacket->setEther_type((unsigned short)this->getType().toShort());
    //TODO - CP Payload
    this->packet = newPacket;
    } catch (std::exception) {
        std::cerr << "Erreur dans la formation du paquet" << std::endl;
    }
}

void EthernetDisplay::sendPacket() {
    this->actualizePacket();
    RawSocket::getInstance().sendPacket(packet);
}
