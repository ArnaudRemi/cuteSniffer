/*
 * Ethernet.cpp
 *
 *  Created on: 1 déc. 2014
 *      Author: cursan_a
 */

#include <string.h>
#include <stdlib.h>
#include "Ethernet.hh"
#include "../Utils.hh"

Ethernet::Ethernet() :
		buffer(NULL), buffSize(sizeof(Ethernet::s_ethernet)) {
	memset(&this->header, 0, sizeof(Ethernet::s_ethernet));
}

Ethernet::Ethernet(char* data, int dataSize) :
		buffer(data), buffSize(dataSize) {
	if (dataSize >= this->getSize())
		memcpy(&this->header, data, sizeof(Ethernet::s_ethernet));
	else
		memset(&this->header, 0, sizeof(Ethernet::s_ethernet));
}

Ethernet::~Ethernet() {
}

std::string Ethernet::getEther_shost() {
	return (Utils::convertByteToMAC(this->header.ether_shost));
}

std::string Ethernet::getEther_dhost() {
	return (Utils::convertByteToMAC(this->header.ether_dhost));
}

short Ethernet::getEther_type() {
	return (this->header.ether_type);
}

void Ethernet::setEther_dhost(std::string mac) {
	memcpy(this->header.ether_dhost, Utils::convertMACToByte(mac), 6);
}

void Ethernet::setEther_shost(std::string mac) {
	memcpy(this->header.ether_shost, Utils::convertMACToByte(mac), 6);
}

void Ethernet::setEther_type(short type) {
	this->header.ether_type = type;
}

int Ethernet::getSize() {
	return sizeof(Ethernet::s_ethernet);
}

std::ostream &operator<<(std::ostream &flux, Ethernet &pqt) {
	flux << "Ethernet(" << pqt.getSize() << ")=[Destination : "
			<< pqt.getEther_dhost() << ", Source : " << pqt.getEther_shost()
			<< ", type : " << pqt.getEther_type() << "]";
	return flux;
}

char* Ethernet::getBuffer() {
	if (this->buffer == NULL)
		this->actualizeBuffer();
	return this->buffer;
}

void Ethernet::setBuffer(char* buffer) {
	this->buffer = buffer;
}

void Ethernet::actualizeBuffer() {
	if (buffer == NULL) {
		if ((buffer = (char *) malloc(sizeof(Ethernet::s_ethernet))) == NULL)
			exit(EXIT_FAILURE);
		this->buffSize = sizeof(Ethernet::s_ethernet);
	}
	memcpy(buffer, &this->header, sizeof(Ethernet::s_ethernet));
}

int Ethernet::getBuffSize() const {
	return buffSize;
}

void Ethernet::setBuffSize(int buffSize) {
	this->buffSize = buffSize;
}
