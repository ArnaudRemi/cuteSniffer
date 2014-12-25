#include "EthernetDisplay.hh"

EthernetDisplay::EthernetDisplay() {

}

EthernetDisplay::EthernetDisplay(Ethernet *paquet) : paquet(paquet),
                                                     shost(paquet->getEther_shost().c_str()),
                                                     dhost(paquet->getEther_dhost().c_str()),
                                                     type(paquet->getEther_typeString().c_str()),
                                                     data(paquet->getPayload().c_str()) {

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
