/*
 * ClientHandler.cpp
 *
 *  Created on: 27 déc. 2014
 *      Author: cursan_a
 */

#include "ClientHandler.hh"

ClientHandler::ClientHandler() {

}
ClientHandler::ClientHandler(ClientHandler const &) : QObject(0){

}

ClientHandler &ClientHandler::operator=(ClientHandler const &) {
    return *this;
}

ClientHandler::ClientHandler(QString const &userMac) : userMac(userMac){
}

void ClientHandler::setUserMac(QString const &userMac) {
    this->userMac = userMac;
}

QQmlListProperty<Client> ClientHandler::getClients() {
    return QQmlListProperty<Client>(this, clients);
}

void ClientHandler::addClient(std::string const &mac) {
    QString qmac(mac.c_str());
    for (Client *client : clients) {
        if (!client->getMac().compare(qmac))
            return;
    }
    if (qmac.compare(userMac)) {
        clients.push_back(new Client(qmac));
        emit clientsChanged();
    }
}

void ClientHandler::addClient(std::string const &mac, std::string const &ip) {
    QString qmac(mac.c_str());
    QString qip(ip.c_str());
    for (Client *client : clients) {
        if (!client->getMac().compare(qmac)) {
            client->setIp(qip);
            return;
        }
    }
    if (qmac.compare(userMac)) {
        clients.push_back(new Client(qmac, qip));
        emit clientsChanged();
    }
}

void ClientHandler::addClient(Ethernet *packet) {
    switch (packet->getEther_type()) {
    case ETHERTYPE_ARP: {
        ARP<Ethernet> arp(*packet);
        addClient(arp.getSha(), arp.getSpa());
        addClient(arp.getTha(), arp.getTpa());
        break;
    }
    case ETHERTYPE_IP: {
        IP<Ethernet> ip(*packet);
        addClient(ip.getEther_shost(), ip.getIpSrc());
        addClient(ip.getEther_dhost(), ip.getIpDst());
        break;
    }
    case ETHERTYPE_IPV6: {
        IPV6<Ethernet> ipv6(*packet);
        addClient(ipv6.getEther_shost(), ipv6.getIp6Src());
        addClient(ipv6.getEther_dhost(), ipv6.getIp6Dest());
        break;
    }
    default: {
        addClient(packet->getEther_shost());
        addClient(packet->getEther_dhost());
        break;
    }
    }
}
