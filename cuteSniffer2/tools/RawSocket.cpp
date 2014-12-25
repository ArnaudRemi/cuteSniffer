#include <iostream>
#include "RawSocket.hh"
#include "ARP.hpp"
#include "IP.hpp"
#include "IPV6.hpp"


RawSocket::RawSocket() {
#if __APPLE__
    this->sock = socket(PF_INET, SOCK_RAW, htons(IPPROTO_TCP));
#else
    this->sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
#endif
	this->buffer = new char[BUFFER_SIZE + 1];
}

RawSocket::~RawSocket() {
	delete[] this->buffer;
	close(this->sock);
}

bool RawSocket::goPromiscious(std::string if_name) {
	struct ifreq ifr;
	struct packet_mreq mr;
    //struct sockaddr_ll sll;

	ifr.ifr_ifindex = 0;
    strcpy(ifr.ifr_name, if_name.c_str());
	if (setsockopt(this->sock, SOL_SOCKET, SO_BINDTODEVICE, &ifr, sizeof(ifr))
			< 0) {
		std::cout << "Fail to bind " << if_name << " to the raw socket"
				<< std::endl;
	}
	if (ioctl(this->sock, SIOGIFINDEX, &ifr) < 0) {
		perror("ioctl error ");
		return 1;
	}

	memset(&mr, 0, sizeof(mr));
	mr.mr_ifindex = ifr.ifr_ifindex;
	mr.mr_type = PACKET_MR_PROMISC;
	if (setsockopt(this->sock, SOL_PACKET, PACKET_ADD_MEMBERSHIP, (char *) &mr,
			sizeof(mr)) < 0) {
		perror("setsockopt error ");
		return 1;
	}
	return 0;
}

/*int RawSocket::readNext(){
 int data_size;

 data_size = read(this->sock, this->buffer, BUFFER_SIZE);
 if(data_size < 0)
 {
 std::cout << "read error , failed to get packets" << std::endl;
 return -1;
 }

 std::cout << data_size << std::endl;

 this->readSize = data_size;
 return data_size;
 }

 L2_Packet *RawSocket::getPacket(){
 L2_Packet *p = new L2_Packet();

 //p->setData(this->buffer);
 //p->setSize(this->readSize);

 p->parseData(this->buffer, this->readSize);
 }*/

Ethernet *RawSocket::getPacket() {
	int data_size;
	fd_set readfds;
	struct timeval timeout;

	FD_SET(this->sock, &readfds);
	timeout.tv_sec = 0;
	timeout.tv_usec = 0;
	if (select(this->sock + 1, &readfds, NULL, NULL, &timeout) == -1)
		return NULL;
	if (!FD_ISSET(this->sock, &readfds))
		return NULL;
	data_size = read(this->sock, this->buffer, BUFFER_SIZE);
	if (data_size < 0) {
		std::cout << "read error , failed to get packets" << std::endl;
		return NULL;
	}
	Ethernet *pqt = new Ethernet(this->buffer, data_size);
	switch (pqt->getEther_type()) {
	case ETHERTYPE_ARP:
		return new ARP<Ethernet>(*pqt);
		break;
	case ETHERTYPE_IP:
		return new IP<Ethernet>(*pqt);
		break;
	case ETHERTYPE_IPV6:
		return new IPV6<Ethernet>(*pqt);
		break;
	}
	return pqt;
}
