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

Ethernet::Ethernet(Ethernet &other) : AProtocol() {
	new (this) Ethernet(other.getBuffer(), other.getBufferSize());
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
	return ntohs(this->header.ether_type);
}

std::string Ethernet::getEther_typeString() {
    short int type = ntohs(this->header.ether_type);
    const char *names[] = {"PUP", "IP", "ARP", "REVARP", "VLAN", "IPV6", "PAE", "RSN_PREAUTH", "LOOPBACK" };
    const int value[] ={ETHERTYPE_PUP, ETHERTYPE_IP, ETHERTYPE_ARP, ETHERTYPE_REVARP,ETHERTYPE_VLAN,
                        ETHERTYPE_IPV6, ETHERTYPE_PAE, ETHERTYPE_RSN_PREAUTH, ETHERTYPE_LOOPBACK};
    for (int i = 0; i < 9; i++) {
        if (value[i] == type)
            return names[i];
    }
    std::string  ret("UNKNOWN (0x");
    std::stringstream sstream;
    sstream << std::hex << type;
    ret += sstream.str();
    ret += ")";
    return ret;
}

std::string Ethernet::getPayload() {
    actualizeBuffer();
    std::string ret = Utils::convertBrutDataToString(this->buffer + this->getTotalSize(),
                                          this->bufferSize - this->getTotalSize());
    std::cout << "PAYLOAD : " << ret << std::endl;
    return ret;
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


std::string Ethernet::getSource() {
	return this->getEther_shost();
}

std::string Ethernet::getDestination() {
	return this->getEther_dhost();
}
