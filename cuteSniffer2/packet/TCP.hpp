/*
 * TCP.hh
 *
 *  Created on: 4 déc. 2014
 *      Author: cursan_a
 */

#ifndef PACKET_TCP_HH_
#define PACKET_TCP_HH_

#include <sstream>
#include <cstring>
#include <iostream>
#include "AProtocol.hh"

template<class T>
class TCP: public ASubProtocol<T> {
private:
	typedef struct s_tcp {
		unsigned short th_sport; /* source port */
		unsigned short th_dport; /* destination port */
		unsigned int th_seq; /* sequence number */
		unsigned int th_ack; /* acknowledgement number */
		unsigned char th_off; /* data offset, rsvd */
#define TH_OFF(th)      (((th)->th_off & 0xf0) >> 4)
		unsigned char th_flags;
#define TH_FIN  0x01
#define TH_SYN  0x02
#define TH_RST  0x04
#define TH_PUSH 0x08
#define TH_ACK  0x10
#define TH_URG  0x20
#define TH_ECE  0x40
#define TH_CWR  0x80
#define TH_FLAGS        (TH_FIN|TH_SYN|TH_RST|TH_ACK|TH_URG|TH_ECE|TH_CWR)
		unsigned short th_win; /* window */
		unsigned short th_sum; /* checksum */
		unsigned short th_urp; /* urgent pointer */
	} tcp_header;
	tcp_header header;
public:
	TCP() {
		memset(&this->header, 0, sizeof(tcp_header));
	}

    TCP(unsigned char* data, int dataSize) :
			ASubProtocol<T>(data, dataSize) {
        if (dataSize >= this->getTotalHeaderSize())
            memcpy(&this->header, data + T::getTotalHeaderSize(), sizeof(tcp_header));
		else
			memset(&this->header, 0, sizeof(tcp_header));
	}

	TCP(T &pqt) {
		new (this) TCP(pqt.getBuffer(), pqt.getBufferSize());
	}

	virtual ~TCP() {
    }

    virtual int getTotalHeaderSize() {
        return T::getTotalHeaderSize() + sizeof(tcp_header);
    }

    virtual int getTotalNbByteInBufferNeed() {
        return this->getTotalHeaderSize();
    }

	virtual void setDataOnBuffer() {
		T::setDataOnBuffer();
        memcpy(this->buffer + T::getTotalHeaderSize() , &(this->header), sizeof(tcp_header));
	}

	virtual std::string toString() {
		std::ostringstream stream;
        stream << T::toString() << "TCP(" << this->getTotalHeaderSize()
				<< ")=[Source Port: " << this->getThSport()
				<< ", Destination Port: " << this->getThDport() << "]"
				<< std::endl;
		return stream.str();
	}

	unsigned int getThAck() const {
		return header.th_ack;
	}

	void setThAck(unsigned int thAck) {
		header.th_ack = thAck;
	}

	unsigned short getThDport() const {
		return header.th_dport;
	}

	void setThDport(unsigned short thDport) {
		header.th_dport = thDport;
	}

	unsigned char getThFlags() const {
		return header.th_flags;
	}

	void setThFlags(unsigned char thFlags) {
		header.th_flags = thFlags;
	}

	unsigned char getThOff() const {
		return header.th_off;
	}

	void setThOff(unsigned char thOff) {
		header.th_off = thOff;
	}

	unsigned int getThSeq() const {
		return header.th_seq;
	}

	void setThSeq(unsigned int thSeq) {
		header.th_seq = thSeq;
	}

	unsigned short getThSport() const {
		return header.th_sport;
	}

	void setThSport(unsigned short thSport) {
		header.th_sport = thSport;
	}

	unsigned short getThSum() const {
		return header.th_sum;
	}

	void setThSum(unsigned short thSum) {
		header.th_sum = thSum;
	}

	unsigned short getThUrp() const {
		return header.th_urp;
	}

	void setThUrp(unsigned short thUrp) {
		header.th_urp = thUrp;
	}

	unsigned short getThWin() const {
		return header.th_win;
	}

	void setThWin(unsigned short thWin) {
		header.th_win = thWin;
	}
};

#endif /* PACKET_TCP_HH_ */
