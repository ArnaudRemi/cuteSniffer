#ifndef __CUTE_UDP_PACKET__
#define __CUTE_UDP_PACKET__

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "L4_Packet.h"


typedef struct s_udp {
    unsigned short udph_srcport;
    unsigned short udph_destport;
    unsigned short udph_len;
    unsigned short udph_chksum;
} udp_header;

class UDP_Packet : public L4_Packet {

    udp_header *head;
    char *content;

public:
    UDP_Packet();
    ~UDP_Packet();

    bool parseData(char * data, int size);
};

#endif