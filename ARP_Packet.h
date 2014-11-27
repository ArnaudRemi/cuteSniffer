#ifndef __CUTE_ARP_PACKET__
#define __CUTE_ARP_PACKET__

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "L3_Packet.h"

#define ARP_REQUEST 1   /* ARP Request             */
#define ARP_REPLY 2     /* ARP Reply               */

typedef struct s_arp {
    unsigned short htype;      /* Hardware Type           */
    unsigned short ptype;      /* Protocol Type           */
    unsigned char hlen;        /* Hardware Address Length */
    unsigned char plen;        /* Protocol Address Length */
    unsigned short oper;       /* Operation Code          */
    unsigned char sha[6];      /* Sender hardware address */
    unsigned char spa[4];      /* Sender IP address       */
    unsigned char tha[6];      /* Target hardware address */
    unsigned char tpa[4];      /* Target IP address       */
} arp_header;

class ARP_Packet : public L3_Packet{

    arp_header *head;

public:
    ARP_Packet();
    ~ARP_Packet();

    bool parseData(char *data, int size);
};

#endif