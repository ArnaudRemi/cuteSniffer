/*
 * Ethernet.cpp
 *
 *  Created on: 1 déc. 2014
 *      Author: cursan_a
 */

#include <sstream>
#include <string.h>
#include <stdlib.h>
#include "Ethernet.hh"
#include "Utils.hh"

Ethernet::Ethernet() :
		AProtocol(NULL, sizeof(Ethernet::s_ethernet)) {
	memset(&this->header, 0, sizeof(Ethernet::s_ethernet));
}

Ethernet::Ethernet(char* data, int dataSize) :
		AProtocol(data, dataSize) {
	if (dataSize >= this->getTotalSize())
		memcpy(&this->header, data, sizeof(Ethernet::s_ethernet));
	else
		memset(&this->header, 0, sizeof(Ethernet::s_ethernet));
}

Ethernet::~Ethernet() {
}

int Ethernet::getTotalSize() {
	return sizeof(Ethernet::s_ethernet);
}

std::string Ethernet::toString() {
	std::ostringstream stream;
	stream << "Ethernet(" << this->getTotalSize() << ")=[Destination : "
			<< this->getEther_dhost() << ", Source : " << this->getEther_shost()
			<< ", type : " << this->getEther_type() << "]" << std::endl;
	return stream.str();
}

void Ethernet::setDataOnBuffer() {
	memcpy(this->buffer, &(this->header), sizeof(Ethernet::ethernet_header));
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
	unsigned char *dhost = Utils::convertMACToByte(mac);
	memcpy(this->header.ether_dhost, dhost, 6);
	free(dhost);
}

void Ethernet::setEther_shost(std::string mac) {
	unsigned char *shost = Utils::convertMACToByte(mac);
	memcpy(this->header.ether_shost, shost, 6);
	free(shost);
}

void Ethernet::setEther_type(short type) {
	this->header.ether_type = type;
}
