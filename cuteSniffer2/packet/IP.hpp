/*
 * IP.hh
 *
 *  Created on: 2 déc. 2014
 *      Author: cursan_a
 */

#ifndef PACKET_IP_HH_
#define PACKET_IP_HH_

#include <sstream>
#include <cstring>
#include <iostream>
#include "AProtocol.hh"
#include "Utils.hh"

template<class T>
class IP: public ASubProtocol<T> {
private:
	typedef struct s_ip {
		unsigned char ip_vhl; /* version << 4 | header length >> 2 */
		unsigned char ip_tos; /* type of service */
		unsigned short ip_len; /* total length */
		unsigned short ip_id; /* identification */
		unsigned short ip_off; /* fragment offset field */
#define IP_RF 0x8000            /* reserved fragment flag */
#define IP_DF 0x4000            /* dont fragment flag */
#define IP_MF 0x2000            /* more fragments flag */
#define IP_OFFMASK 0x1fff       /* mask for fragmenting bits */
		unsigned char ip_ttl; /* time to live */
		unsigned char ip_p; /* protocol */
		unsigned short ip_sum; /* checksum */
		struct in_addr ip_src; /* source address */
		struct in_addr ip_dst; /* destination address */
	} ip_header;
#define IP_HL(ip)	(((ip)->ip_vhl) & 0x0f)
#define IP_V(ip)	(((ip)->ip_vhl) >> 4)
	ip_header header;
public:
	IP() {
		memset(&this->header, 0, sizeof(ip_header));
	}

    IP(unsigned char* data, int dataSize) :
			ASubProtocol<T>(data, dataSize) {
        if (dataSize >= this->getTotalHeaderSize())
            memcpy(&this->header, data + T::getTotalHeaderSize(), sizeof(ip_header));
		else
			memset(&this->header, 0, sizeof(ip_header));
	}

	IP(T &pqt) {
		new (this) IP(pqt.getBuffer(), pqt.getBufferSize());
	}

	virtual ~IP() {
	}

    virtual int getTotalHeaderSize() {
        return T::getTotalHeaderSize() + sizeof(ip_header);
    }

    virtual int getTotalNbByteInBufferNeed() {
        return this->getTotalHeaderSize();
    }

	virtual void setDataOnBuffer() {
		T::setDataOnBuffer();
        memcpy(this->buffer + T::getTotalHeaderSize() , &(this->header), sizeof(ip_header));
	}

	virtual std::string toString() {
		std::ostringstream stream;
        stream << T::toString() << "IP(" << this->getTotalHeaderSize()
				<< ")=[IP Source : " << this->getIpSrc()
				<< ", IP Destination : " << this->getIpDst() << "]" << std::endl;
		return stream.str();
	}

	std::string getIpDst() const {
		return Utils::convertIn_addrToIP(header.ip_dst);
	}

	void setIpDst(std::string ipDst) {
		header.ip_dst = Utils::convertIPtoIn_addr(ipDst);
	}

	unsigned short getIpId() const {
		return header.ip_id;
	}

	void setIpId(unsigned short ipId) {
		header.ip_id = ipId;
	}

	unsigned short getIpLen() const {
		return header.ip_len;
	}

	void setIpLen(unsigned short ipLen) {
		header.ip_len = ipLen;
	}

	unsigned short getIpOff() const {
		return header.ip_off;
	}

	void setIpOff(unsigned short ipOff) {
		header.ip_off = ipOff;
	}

	unsigned char getIpP() const {
		return header.ip_p;
	}

	void setIpP(unsigned char ipP) {
		header.ip_p = ipP;
	}

	std::string getIpSrc() const {
		return Utils::convertIn_addrToIP(header.ip_src);
	}

	void setIpSrc(std::string ipSrc) {
		header.ip_src = Utils::convertIPtoIn_addr(ipSrc);
	}

	unsigned short getIpSum() const {
		return header.ip_sum;
	}

	void setIpSum(unsigned short ipSum) {
		header.ip_sum = ipSum;
	}

	unsigned char getIpTos() const {
		return header.ip_tos;
	}

	void setIpTos(unsigned char ipTos) {
		header.ip_tos = ipTos;
	}

	unsigned char getIpTtl() const {
		return header.ip_ttl;
	}

	void setIpTtl(unsigned char ipTtl) {
		header.ip_ttl = ipTtl;
	}

	unsigned char getIpVhl() const {
		return header.ip_vhl;
	}

	void setIpVhl(unsigned char ipVhl) {
		header.ip_vhl = ipVhl;
	}
	virtual std::string getSource() {
		return this->getIpSrc();
	}
	virtual std::string getDestination() {
		return this->getIpDst();
	}

};

#endif /* PACKET_IP_HH_ */
