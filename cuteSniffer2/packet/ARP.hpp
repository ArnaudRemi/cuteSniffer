/*
 * ARP.hh
 *
 *  Created on: 1 déc. 2014
 *      Author: cursan_a
 */

#ifndef PACKET_ARP_HH_
#define PACKET_ARP_HH_

#include <sstream>
#include <cstring>
#include "AProtocol.hh"
#include "Utils.hh"

template<class T>
class ARP: public ASubProtocol<T> {
private:
	typedef struct s_arp {
		unsigned short htype; /* Hardware Type           */
		unsigned short ptype; /* Protocol Type           */
		unsigned char hlen; /* Hardware Address Length */
		unsigned char plen; /* Protocol Address Length */
		unsigned short oper; /* Operation Code          */
		unsigned char sha[6]; /* Sender hardware address */
		unsigned char spa[4]; /* Sender IP address       */
		unsigned char tha[6]; /* Target hardware address */
		unsigned char tpa[4]; /* Target IP address       */
	} arp_header;

	arp_header header;
public:

	ARP() {
		memset(&this->header, 0, sizeof(arp_header));
	}

	ARP(char* data, int dataSize) :
			ASubProtocol<T>(data, dataSize) {
		if (dataSize >= this->getTotalSize())
			memcpy(&this->header, data + T::getTotalSize(), sizeof(arp_header));
		else
			memset(&this->header, 0, sizeof(arp_header));
	}

	ARP(T &pqt) {
		new (this) ARP(pqt.getBuffer(), pqt.getBufferSize());
	}

	virtual ~ARP() {
	}

	int getTotalSize() {
		return T::getTotalSize() + sizeof(arp_header);
	}

	virtual void setDataOnBuffer() {
		T::setDataOnBuffer();
		memcpy(this->buffer + T::getTotalSize() , &(this->header), sizeof(arp_header));
	}

	virtual std::string toString() {
		std::ostringstream stream;
		stream << T::toString() << "ARP(" << this->getTotalSize()
				<< ")=[Target IP : " << this->getTpa() << ", Sender IP : "
				<< this->getSpa() << "]" << std::endl;
		return stream.str();
	}

	unsigned char getHlen() const {
		return header.hlen;
	}

	void setHlen(unsigned char hlen) {
		this->header.hlen = hlen;
	}

	unsigned short getHtype() const {
		return header.htype;
	}

	void setHtype(unsigned short htype) {
		this->header.htype = htype;
	}

	unsigned short getOper() const {
		return header.oper;
	}

	std::string getSha() {
		return (Utils::convertByteToMAC(this->header.sha));
	}

	std::string getSpa() {
		return (Utils::convertByteToIP(this->header.spa));
	}

	std::string getTha() {
		return (Utils::convertByteToMAC(this->header.tha));
	}

	std::string getTpa() {
		return (Utils::convertByteToIP(this->header.tpa));
	}

	void setOper(unsigned short oper) {
		this->header.oper = oper;
	}

	unsigned char getPlen() const {
		return header.plen;
	}

	void setPlen(unsigned char plen) {
		this->header.plen = plen;
	}

	unsigned short getPtype() const {
		return header.ptype;
	}

	void setPtype(unsigned short ptype) {
		this->header.ptype = ptype;
	}

	void setSha(std::string sha) {
		unsigned char *mac = Utils::convertMACToByte(sha);
		memcpy(this->header.sha, mac, 6);
		free(mac);
	}

	void setSpa(std::string spa) {
		unsigned char *ip = Utils::convertIPToByte(spa);
		memcpy(this->header.spa, ip, 4);
		free(ip);
	}

	void setTha(std::string tha) {
		unsigned char *mac = Utils::convertMACToByte(tha);
		memcpy(this->header.tha, mac, 6);
		free(mac);
	}

	void setTpa(std::string tpa) {
		unsigned char *ip = Utils::convertIPToByte(tpa);
		memcpy(this->header.tpa, ip, 4);
		free(ip);
	}

	virtual std::string getSource() {
		return this->getSpa();
	}
	virtual std::string getDestination() {
		return this->getSha();
	}

};

#endif /* PACKET_ARP_HH_ */
