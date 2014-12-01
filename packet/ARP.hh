/*
 * ARP.hh
 *
 *  Created on: 1 déc. 2014
 *      Author: cursan_a
 */

#ifndef PACKET_ARP_HH_
#define PACKET_ARP_HH_

#include <iostream>
#include "Ethernet.hh"

class ARP: public Ethernet {
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
	ARP();
	ARP(char* data, int dataSize);
	ARP(Ethernet &pqt);
	virtual ~ARP();
	unsigned short getHtype() const;
	unsigned short getPtype() const;
	unsigned char getHlen() const;
	unsigned char getPlen() const;
	unsigned short getOper() const;
	std::string getSha();
	std::string getSpa();
	std::string getTha();
	std::string getTpa();
	void setHtype(unsigned short htype);
	void setPtype(unsigned short ptype);
	void setHlen(unsigned char hlen);
	void setPlen(unsigned char plen);
	void setOper(unsigned short oper);
	void setSha(std::string sha);
	void setSpa(std::string spa);
	void setTha(std::string tha);
	void setTpa(std::string tpa);
	int getSize();
};

std::ostream &operator<<(std::ostream &flux, ARP &pqt);

#endif /* PACKET_ARP_HH_ */
