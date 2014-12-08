/*
 * ICMP.hh
 *
 *  Created on: 7 déc. 2014
 *      Author: cursan_a
 */

#ifndef PACKET_ICMP_HH_
#define PACKET_ICMP_HH_

#include <sstream>
#include <cstring>
#include <iostream>
#include "AProtocol.hh"

#define ICMP_ECHOREPLY		0	/* Echo Reply			*/
#define ICMP_DEST_UNREACH	3	/* Destination Unreachable	*/
#define ICMP_SOURCE_QUENCH	4	/* Source Quench		*/
#define ICMP_REDIRECT		5	/* Redirect (change route)	*/
#define ICMP_ECHO			8	/* Echo Request			*/
#define ICMP_TIME_EXCEEDED	11	/* Time Exceeded		*/
#define ICMP_PARAMETERPROB	12	/* Parameter Problem		*/
#define ICMP_TIMESTAMP		13	/* Timestamp Request		*/
#define ICMP_TIMESTAMPREPLY	14	/* Timestamp Reply		*/
#define ICMP_INFO_REQUEST	15	/* Information Request		*/
#define ICMP_INFO_REPLY		16	/* Information Reply		*/
#define ICMP_ADDRESS		17	/* Address Mask Request		*/
#define ICMP_ADDRESSREPLY	18	/* Address Mask Reply		*/
#define NR_ICMP_TYPES		18

/* Codes for UNREACH. */
#define ICMP_NET_UNREACH	0	/* Network Unreachable		*/
#define ICMP_HOST_UNREACH	1	/* Host Unreachable		*/
#define ICMP_PROT_UNREACH	2	/* Protocol Unreachable		*/
#define ICMP_PORT_UNREACH	3	/* Port Unreachable		*/
#define ICMP_FRAG_NEEDED	4	/* Fragmentation Needed/DF set	*/
#define ICMP_SR_FAILED		5	/* Source Route failed		*/
#define ICMP_NET_UNKNOWN	6
#define ICMP_HOST_UNKNOWN	7
#define ICMP_HOST_ISOLATED	8
#define ICMP_NET_ANO		9
#define ICMP_HOST_ANO		10
#define ICMP_NET_UNR_TOS	11
#define ICMP_HOST_UNR_TOS	12
#define ICMP_PKT_FILTERED	13	/* Packet filtered */
#define ICMP_PREC_VIOLATION	14	/* Precedence violation */
#define ICMP_PREC_CUTOFF	15	/* Precedence cut off */
#define NR_ICMP_UNREACH		15	/* instead of hardcoding immediate value */

/* Codes for REDIRECT. */
#define ICMP_REDIR_NET		0	/* Redirect Net			*/
#define ICMP_REDIR_HOST		1	/* Redirect Host		*/
#define ICMP_REDIR_NETTOS	2	/* Redirect Net for TOS		*/
#define ICMP_REDIR_HOSTTOS	3	/* Redirect Host for TOS	*/

/* Codes for TIME_EXCEEDED. */
#define ICMP_EXC_TTL		0	/* TTL count exceeded		*/
#define ICMP_EXC_FRAGTIME	1	/* Fragment Reass time exceeded	*/

template<class T>
class ICMP: public ASubProtocol<T> {
private:
	typedef struct s_icmp {
		unsigned char type; /* message type */
		unsigned char code; /* type sub-code */
		unsigned short checksum;
		union {
			struct {
				unsigned short id;
				unsigned short sequence;
			} echo; /* echo datagram */
			unsigned int gateway; /* gateway address */
			struct {
				unsigned short unused;
				unsigned short mtu;
			} frag; /* path mtu discovery */
		} un;
	} icmp_header;
	icmp_header header;
public:
	ICMP() {
		memset(&this->header, 0, sizeof(icmp_header));
	}

	ICMP(char* data, int dataSize) :
			ASubProtocol<T>(data, dataSize) {
		if (dataSize >= this->getTotalSize())
			memcpy(&this->header, data + T::getTotalSize(),
					sizeof(icmp_header));
		else
			memset(&this->header, 0, sizeof(icmp_header));
	}

	ICMP(T &pqt) {
		new (this) ICMP(pqt.getBuffer(), pqt.getBufferSize());
	}

	virtual ~ICMP() {
	}

	int getTotalSize() {
		return T::getTotalSize() + sizeof(icmp_header);
	}

	virtual void setDataOnBuffer() {
		T::setDataOnBuffer();
		memcpy(this->buffer + T::getTotalSize(), &(this->header),
				sizeof(icmp_header));
	}

	virtual std::string toString() {
		std::ostringstream stream;
		stream << T::toString() << "ICMP(" << this->getTotalSize()
				<< ")=[type : " << this->getType() << "]" << std::endl;
		return stream.str();
	}

	unsigned short getChecksum() const {
		return this->header.checksum;
	}

	void setChecksum(unsigned short checksum) {
		this->header.checksum = checksum;
	}

	unsigned char getCode() const {
		return this->header.code;
	}

	void setCode(unsigned char code) {
		this->header.code = code;
	}

	unsigned int getGateway() const {
		return this->header.gateway;
	}

	void setGateway(unsigned int gateway) {
		this->header.gateway = gateway;
	}

	unsigned char getType() const {
		return this->header.type;
	}

	void setType(unsigned char type) {
		this->header.type = type;
	}
};
#endif /* PACKET_ICMP_HH_ */
