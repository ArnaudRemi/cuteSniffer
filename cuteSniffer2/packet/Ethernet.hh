/*
 * Ethernet.hh
 *
 *  Created on: 1 déc. 2014
 *      Author: cursan_a
 */

#ifndef PACKET_ETHERNET_HH_
#define PACKET_ETHERNET_HH_

#define	ETHERTYPE_PUP           0x0200	/* PUP protocol */
#define	ETHERTYPE_IP            0x0800	/* IP protocol */
#define ETHERTYPE_ARP           0x0806	/* Addr. resolution protocol */
#define ETHERTYPE_REVARP        0x8035	/* reverse Addr. resolution protocol */
#define	ETHERTYPE_VLAN          0x8100	/* IEEE 802.1Q VLAN tagging */
#define ETHERTYPE_IPV6          0x86dd	/* IPv6 */
#define ETHERTYPE_PAE           0x888e  /* EAPOL PAE/802.1x */
#define ETHERTYPE_RSN_PREAUTH	0x88c7  /* 802.11i / RSN Pre-Authentication */
#define	ETHERTYPE_LOOPBACK      0x9000	/* used to test interfaces */

#include <iostream>
#include "AProtocol.hh"

class Ethernet : public AProtocol {
private:
	typedef struct s_ethernet {
		unsigned char ether_dhost[6]; /* destination host address */
		unsigned char ether_shost[6]; /* source host address */
		unsigned short ether_type; /* IP? ARP? RARP? etc */
	} ethernet_header;
	ethernet_header header;
public:
	Ethernet();
	Ethernet(char *data, int dataSize);
	Ethernet(Ethernet &other);
	virtual ~Ethernet();
	std::string getEther_dhost();
	std::string getEther_shost();
	short getEther_type();
    std::string getEther_typeString();
    std::string getPayload();
	void setEther_dhost(std::string mac);
	void setEther_shost(std::string mac);
	void setEther_type(short type);
	virtual int getTotalSize();
	virtual std::string toString();
	virtual void setDataOnBuffer();
	virtual std::string getSource();
	virtual std::string getDestination();
};

#endif /* PACKET_ETHERNET_HH_ */
