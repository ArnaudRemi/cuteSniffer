#ifndef __CUTE_RAW_SOCKET__
#define __CUTE_RAW_SOCKET__

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <net/ethernet.h>
#include <netinet/ip_icmp.h>   //Provides declarations for icmp header
#include <netinet/udp.h>   //Provides declarations for udp header
#include <netinet/tcp.h>   //Provides declarations for tcp header
#include <netinet/ip.h>    //Provides declarations for ip header
#include <sys/types.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <net/ethernet.h>  //For ether_header
#include <net/if.h>
#include <netpacket/packet.h>
#include <stdio.h> //For standard things
#include <stdlib.h>    //malloc
#include <string.h>    //memset
#include <string>
#include "Ethernet.hh"

#define BUFFER_SIZE 65535

class RawSocket {

    int sock;
    unsigned char *buffer;
    int readSize;

public:
    RawSocket();
    ~RawSocket();

    bool runPromiscious(std::string if_name);
    void stopPromiscious();
    Ethernet *getPacket();
    /*int readNext();
    L2_Packet *getPacket();*/


};

#endif
