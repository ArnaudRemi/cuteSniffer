/*
 * UDP.hh
 *
 *  Created on: 4 déc. 2014
 *      Author: cursan_a
 */

#ifndef PACKET_UDP_HH_
#define PACKET_UDP_HH_

#include <sstream>
#include <cstring>
#include <iostream>
#include "AProtocol.hh"

template<class T>
class UDP: public ASubProtocol<T> {
private:
	typedef struct s_udp {
		unsigned short udph_srcport;
		unsigned short udph_destport;
		unsigned short udph_len;
		unsigned short udph_chksum;
	} udp_header;
	udp_header header;
public:
	UDP() {
		memset(&this->header, 0, sizeof(udp_header));
	}

    UDP(unsigned char* data, int dataSize) :
			ASubProtocol<T>(data, dataSize) {
        if (dataSize >= this->getTotalHeaderSize())
            memcpy(&this->header, data + T::getTotalHeaderSize(), sizeof(udp_header));
		else
			memset(&this->header, 0, sizeof(udp_header));
	}

	UDP(T &pqt) {
		new (this) UDP(pqt.getBuffer(), pqt.getBufferSize());
	}

	virtual ~UDP() {
	}

    virtual int getTotalHeaderSize() {
        return T::getTotalHeaderSize() + sizeof(udp_header);
    }

    virtual int getTotalNbByteInBufferNeed() {
        return this->getTotalHeaderSize();
    }

	virtual void setDataOnBuffer() {
		T::setDataOnBuffer();
        memcpy(this->buffer + T::getTotalHeaderSize(), &(this->header),
				sizeof(udp_header));
	}

	virtual std::string toString() {
		std::ostringstream stream;
        stream << T::toString() << "UDP(" << this->getTotalHeaderSize()
				<< ")=[Source Port: " << this->getUdphSrcport()
				<< ", Destination Port: " << this->getUdphDestport()
				<< ", Len:" << this->getUdphLen()
				<< "]" << std::endl;
		return stream.str();
	}

	unsigned short getUdphChksum() const {
		return header.udph_chksum;
	}

	void setUdphChksum(unsigned short udphChksum) {
		header.udph_chksum = udphChksum;
	}

	unsigned short getUdphDestport() const {
		return header.udph_destport;
	}

	void setUdphDestport(unsigned short udphDestport) {
		header.udph_destport = udphDestport;
	}

	unsigned short getUdphLen() const {
		return header.udph_len;
	}

	void setUdphLen(unsigned short udphLen) {
		header.udph_len = udphLen;
	}

	unsigned short getUdphSrcport() const {
		return header.udph_srcport;
	}

	void setUdphSrcport(unsigned short udphSrcport) {
		header.udph_srcport = udphSrcport;
	}
};

#endif /* PACKET_UDP_HH_ */
