#include <iostream>
#include "RawSocket.hh"
#include "ARP.hpp"
#include "IP.hpp"
#include "IPV6.hpp"

RawSocket::RawSocket() {
    this->buffer = new unsigned char[BUFFER_SIZE + 1];
}

RawSocket RawSocket::instance = RawSocket();
RawSocket &RawSocket::getInstance() {
    return RawSocket::instance;
}

RawSocket::~RawSocket() {
    delete[] this->buffer;
    close(this->sock);
}

bool RawSocket::runPromiscious(std::string if_name) {
    this->sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    struct packet_mreq mr;

    ifr.ifr_ifindex = 0;
    strcpy(ifr.ifr_name, if_name.c_str());
    if (setsockopt(this->sock, SOL_SOCKET, SO_BINDTODEVICE, &ifr, sizeof(ifr)) < 0) {
        std::cout << "Fail to bind " << if_name << " to the raw socket" << std::endl;
    }
    if (ioctl(this->sock, SIOGIFINDEX, &ifr) < 0) {
        perror("ioctl error ");
        return 1;
    }

    memset(&mr, 0, sizeof(mr));
    mr.mr_ifindex = ifr.ifr_ifindex;
    mr.mr_type = PACKET_MR_PROMISC;
    if (setsockopt(this->sock, SOL_PACKET, PACKET_ADD_MEMBERSHIP, (char *) &mr, sizeof(mr)) < 0) {
        perror("setsockopt error ");
        return 1;
    }
    return 0;
}

void RawSocket::stopPromiscious() {
    close(this->sock);
}

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

void RawSocket::sendPacket(Ethernet *packet) {
    struct sockaddr_ll 	socket_address;

    packet->actualizeBuffer();
    memset(&socket_address, 0, sizeof(socket_address));
    socket_address.sll_ifindex = ifr.ifr_ifindex;
    socket_address.sll_halen = ETH_ALEN;
    memcpy(socket_address.sll_addr, packet->getEthernetHeader().ether_dhost, 6);
    if (sendto(this->sock, packet->getBuffer(), packet->getBufferSize(), 0,
               (struct sockaddr*)&socket_address, sizeof(struct sockaddr_ll)) < 0)
        perror("Send failed");
}
