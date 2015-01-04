/*
 * Client.cpp
 *
 *  Created on: 27 déc. 2014
 *      Author: cursan_a
 */

#include "Client.hh"

Client::Client() {

}

Client::Client(QString const &mac) : mac(mac), router(false){
}

Client::Client(QString const &mac, QString const &ip) : mac(mac), ip(ip), router(false) {
}

Client::Client(QString const &mac, bool router) : mac(mac), router(router){
}

Client::Client(QString const &mac, QString const &ip, bool router) : mac(mac), ip(ip), router(router) {
}

QString Client::getIp() const {
	return ip;
}

void Client::setIp(QString ip) {
	this->ip = ip;
    emit ipChanged();
}

QString Client::getMac() const {
	return mac;
}

void Client::setMac(QString mac) {
	this->mac = mac;
    emit macChanged();
}

bool Client::isRouter() const {
    return router;
}

void Client::setRouter(bool router) {
    this->router = router;
    emit routerChanged();
}
