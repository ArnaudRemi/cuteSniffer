/*
 * IP.hh
 *
 *  Created on: 2 déc. 2014
 *      Author: cursan_a
 */

#ifndef PACKET_IP_HH_
#define PACKET_IP_HH_

#include "Ethernet.hh"

class IP: public Ethernet {
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
	unsigned char getIpVhl() const;
	unsigned char getIpTos() const;
	unsigned short getIpLen() const;
	unsigned short getIpId() const;
	unsigned short getIpOff() const;
	unsigned char getIpTtl() const;
	unsigned char getIpP() const;
	unsigned short getIpSum() const;
	struct in_addr getIpSrc() const;
	struct in_addr getIpDst() const;
	void setIpVhl(unsigned char ipVhl);
	void setIpTos(unsigned char ipTos);
	void setIpLen(unsigned short ipLen);
	void setIpId(unsigned short ipId);
	void setIpOff(unsigned short ipOff);
	void setIpTtl(unsigned char ipTtl);
	void setIpP(unsigned char ipP);
	void setIpSum(unsigned short ipSum);
	void setIpSrc(struct in_addr ipSrc); //TODO - finir get / set
	void setIpDst(struct in_addr ipDst);
};

#endif /* PACKET_IP_HH_ */
