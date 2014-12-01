/*
 * ARP.cpp
 *
 *  Created on: 1 déc. 2014
 *      Author: cursan_a
 */

#include <string.h>
#include "ARP.hh"
#include "../Utils.hh"

ARP::ARP() {
	memset(&this->header, 0, sizeof(ARP::s_arp));
}

ARP::ARP(char* data, int dataSize) :
		Ethernet(data, dataSize) {
	if (dataSize >= this->getSize())
		memcpy(&this->header, data + Ethernet::getSize(), sizeof(ARP::s_arp));
	else
		memset(&this->header, 0, sizeof(ARP::s_arp));
}

ARP::ARP(Ethernet &pqt) {
	new (this) ARP(pqt.getBuffer(), pqt.getBuffSize());
}

ARP::~ARP() {
}

unsigned char ARP::getHlen() const {
	return header.hlen;
}

void ARP::setHlen(unsigned char hlen) {
	this->header.hlen = hlen;
}

unsigned short ARP::getHtype() const {
	return header.htype;
}

void ARP::setHtype(unsigned short htype) {
	this->header.htype = htype;
}

unsigned short ARP::getOper() const {
	return header.oper;
}

std::string ARP::getSha() {
	return (Utils::convertByteToMAC(this->header.sha));
}

std::string ARP::getSpa() {
	return (Utils::convertByteToIP(this->header.spa));
}

std::string ARP::getTha() {
	return (Utils::convertByteToMAC(this->header.tha));
}

std::string ARP::getTpa() {
	return (Utils::convertByteToIP(this->header.tpa));
}

void ARP::setOper(unsigned short oper) {
	this->header.oper = oper;
}

unsigned char ARP::getPlen() const {
	return header.plen;
}

void ARP::setPlen(unsigned char plen) {
	this->header.plen = plen;
}

unsigned short ARP::getPtype() const {
	return header.ptype;
}

void ARP::setPtype(unsigned short ptype) {
	this->header.ptype = ptype;
}

void ARP::setSha(std::string sha) {
	memcpy(this->header.sha, Utils::convertMACToByte(sha), 6);
}

void ARP::setSpa(std::string spa) {
	memcpy(this->header.spa, Utils::convertIPToByte(spa), 4);
}

void ARP::setTha(std::string tha) {
	memcpy(this->header.tha, Utils::convertMACToByte(tha), 6);
}

void ARP::setTpa(std::string tpa) {
	memcpy(this->header.tpa, Utils::convertIPToByte(tpa), 4);
}

int ARP::getSize() {
	return Ethernet::getSize() + sizeof(ARP::s_arp);
}

std::ostream &operator<<(std::ostream &flux, ARP &pqt) {
	flux << (Ethernet &) pqt << std::endl << "ARP(" << pqt.getSize()
			<< ")=[Target IP : " << pqt.getTpa() << ", Sender IP : "
			<< pqt.getSpa() << "]";
	return flux;
}
