#ifndef __CUTE_IPV6_PACKET__
#define __CUTE_IPV6_PACKET__

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include "L3_Packet.h"
#include "L4_Packet.h"

typedef struct s_ipv6 {
    union {
        struct ip6_hdrctl {
            unsigned int ip6_un1_flow; /* 20 bits of flow-ID */
            unsigned short ip6_un1_plen; /* payload length */
            unsigned char  ip6_un1_nxt;  /* next header */
            unsigned char  ip6_un1_hlim; /* hop limit */
        } ip6_un1;
        unsigned char ip6_un2_vfc;   /* 4 bits version, top 4 bits class */
    } ip6_ctlun;
    struct in6_addr ip6_src;        /* source address */
    struct in6_addr ip6_dst;        /* destination address */
} ipv6_header;

class IPV6_Packet : public L3_Packet {

    ipv6_header *head;
    L4_Packet *content;

public:
    IPV6_Packet();
    ~IPV6_Packet();

    bool parse_data(char *data, int size);
};


#endif