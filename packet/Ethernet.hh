/*
 * Ethernet.hh
 *
 *  Created on: 1 déc. 2014
 *      Author: cursan_a
 */

#ifndef PACKET_ETHERNET_HH_
#define PACKET_ETHERNET_HH_

#include <iostream>

class Ethernet {
private:
	typedef struct s_ethernet {
		unsigned char ether_dhost[6]; /* destination host address */
		unsigned char ether_shost[6]; /* source host address */
		unsigned short ether_type; /* IP? ARP? RARP? etc */
	} ethernet_header;
	char *buffer;
	int buffSize;
	ethernet_header header;
public:
	Ethernet();
	Ethernet(char *data, int dataSize);
	virtual ~Ethernet();
	std::string getEther_dhost();
	std::string getEther_shost();
	short getEther_type();
	void setEther_dhost(std::string mac);
	void setEther_shost(std::string mac);
	void setEther_type(short type);
	int getSize();
	char* getBuffer();
	void setBuffer(char* buffer);
	void actualizeBuffer();
	int getBuffSize() const;
	void setBuffSize(int buffSize);
};

std::ostream &operator<<(std::ostream &flux, Ethernet &pqt);

#endif /* PACKET_ETHERNET_HH_ */
