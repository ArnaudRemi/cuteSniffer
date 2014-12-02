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
#include "../Utils.hh"


template<class T>
class ARP: public ASubProtocol<T> {
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
		memset(&this->header, 0, sizeof(s_arp));
	}

	ARP(char* data, int dataSize) : ASubProtocol<T>(data, dataSize) {
		if (dataSize >= this->getTotalSize())
			memcpy(&this->header, data + T::getTotalSize(), sizeof(s_arp));
		else
			memset(&this->header, 0, sizeof(s_arp));
	}

	ARP(T &pqt) {
		new (this) ARP(pqt.getBuffer(), pqt.getBufferSize());
	}

	~ARP() {
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
		memcpy(this->header.sha, Utils::convertMACToByte(sha), 6);
	}

	void setSpa(std::string spa) {
		memcpy(this->header.spa, Utils::convertIPToByte(spa), 4);
	}

	void setTha(std::string tha) {
		memcpy(this->header.tha, Utils::convertMACToByte(tha), 6);
	}

	void setTpa(std::string tpa) {
		memcpy(this->header.tpa, Utils::convertIPToByte(tpa), 4);
	}

	int getTotalSize() {
		return T::getTotalSize() + sizeof(s_arp);
	}

	virtual void setDataOnBuffer() {
		T::setDataOnBuffer();
		std::cout << "sizeParent" << T::getTotalSize() << std::endl;
	}

	virtual std::string toString() {
		std::ostringstream stream;
		stream << T::toString() << "ARP(" << this->getTotalSize() << ")=[Target IP : " << this->getTpa()
				<< ", Sender IP : " << this->getSpa() << "]" << std::endl;
		return stream.str();
	}

};

#endif /* PACKET_ARP_HH_ */
