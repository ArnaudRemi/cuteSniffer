/*
 * IPV6.hh
 *
 *  Created on: 7 déc. 2014
 *      Author: cursan_a
 */

#ifndef PACKET_IPV6_HH_
#define PACKET_IPV6_HH_

#include <sstream>
#include <cstring>
#include <iostream>
#include "AProtocol.hh"

template<class T>
class IPV6: public ASubProtocol<T> {
private:
	struct s_ip6_hdrctl {
		unsigned int flow; /* 20 bits of flow-ID */
		unsigned short plen; /* payload length */
		unsigned char next_head; /* next header */
		unsigned char hop_limit; /* hop limit */
	};
	typedef struct s_ipv6 {
		union {
			struct s_ip6_hdrctl un1;
			unsigned char un2_vfc; /* 4 bits version, top 4 bits class */
		} ip6_infos;
		struct in6_addr ip6_src; /* source address */
		struct in6_addr ip6_dest; /* destination address */
	} ipv6_header;
	ipv6_header header;
public:
	IPV6() {
		memset(&this->header, 0, sizeof(ipv6_header));
	}

    IPV6(unsigned char* data, int dataSize) :
			ASubProtocol<T>(data, dataSize) {
        if (dataSize >= this->getTotalHeaderSize())
            memcpy(&this->header, data + T::getTotalHeaderSize(), sizeof(ipv6_header));
		else
			memset(&this->header, 0, sizeof(ipv6_header));
	}

	IPV6(T &pqt) {
		new (this) IPV6(pqt.getBuffer(), pqt.getBufferSize());
	}

	virtual ~IPV6() {
    }

    virtual int getTotalHeaderSize() {
        return T::getTotalHeaderSize() + sizeof(ipv6_header);
    }

    virtual int getTotalNbByteInBufferNeed() {
        return this->getTotalHeaderSize();
    }

	virtual void setDataOnBuffer() {
		T::setDataOnBuffer();
        memcpy(this->buffer + T::getTotalHeaderSize() , &(this->header), sizeof(ipv6_header));
	}

	virtual std::string toString() {
		std::ostringstream stream;
        stream << T::toString() << "IPV6(" << this->getTotalHeaderSize()
				<< ")=[Source IP: " << this->getIp6Src()
				<< ", Destination IP: " << this->getIp6Dest() << "]"
				<< std::endl;
		return stream.str();
	}

	unsigned int getFlow() const {
		return this->header.ip6_infos.flow;
	}

	void setFlow(unsigned int flow) {
		this->header.ip6_infos.flow = flow;
	}

	unsigned short getPlen() const {
		return this->header.ip6_infos.plen;
	}

	void setPlen(unsigned short plen) {
		this->header.ip6_infos.plen = plen;
	}

	unsigned char getNextHead() const {
		return this->header.ip6_infos.un1.next_head;
	}

	std::string getNextHead_String(){
		unsigned char c = this->header.ip6_infos.un1.next_head;
		const char *names[] = {"ICMP", "IGMP", "TCP", "UDP"};
		const unsigned char value[] ={0x01, 0x02, 0x06, 0x11};

		for (int i = 0; i < 4; i++) {
			if (value[i] == c)
				return names[i];
		}
		std::string  ret("UNKNOWN (0x");
		std::stringstream sstream;
		sstream << std::hex << c;
		ret += sstream.str();
		ret += ")";
		return ret;
	}

	void setNextHead(unsigned char nextHead) {
		this->header.ip6_infos.next_head = nextHead;
	}

	unsigned char getHopLimit() const {
		return this->header.ip6_infos.hop_limit;
	}

	void setHopLimit(unsigned char hopLimit) {
		this->header.ip6_infos.hop_limit = hopLimit;
	}

	const std::string getIp6Src() const {
		return Utils::convertIn6_addrToIPV6(this->header.ip6_src);
	}

	const std::string getIp6Dest() const {
		return Utils::convertIn6_addrToIPV6(this->header.ip6_dest);
	}

	void setIp6Src(std::string ip6Src) {
		this->header.ip6_src = Utils::convertIPV6toIn6_addr(ip6Src);
	}

	void setIp6Dest(std::string ip6Dest) {
		this->header.ip6_dest = Utils::convertIPV6toIn6_addr(ip6Dest);
	}

	unsigned char getUn2Vfc() const {
		return this->header.un2_vfc;
	}

	void setUn2Vfc(unsigned char un2Vfc) {
		this->header.un2_vfc = un2Vfc;
	}
	virtual std::string getSource() {
		return this->getIp6Src();
	}
	virtual std::string getDestination() {
		return this->getIp6Dest();
	}
};

#endif /* PACKET_IPV6_HH_ */
