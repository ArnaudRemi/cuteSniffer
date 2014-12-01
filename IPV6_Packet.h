#ifndef __CUTE_IPV6_PACKET__
#define __CUTE_IPV6_PACKET__

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include "L3_Packet.h"
#include "L4_Packet.h"
#include "TCP_Packet.h"
#include "UDP_Packet.h"
#include "ICMPV6_Packet.h"

typedef struct s_ipv6 {
    union {
        struct ip6_hdrctl {
            unsigned int   flow; /* 20 bits of flow-ID */
            unsigned short plen; /* payload length */
            unsigned char  next_head; /* next header */
            unsigned char  hop_limit; /* hop limit */
        } un1;
        unsigned char un2_vfc;   /* 4 bits version, top 4 bits class */
    } ip6_infos;
    struct in6_addr ip6_src;        /* source address */
    struct in6_addr ip6_dest;        /* destination address */
} ipv6_header;

class IPV6_Packet : public L3_Packet {

    ipv6_header *head;
    L4_Packet *content;

public:
    IPV6_Packet();
    ~IPV6_Packet();

    bool parse_data(char *data, int size);

    std::string verboseDestAddr();
    std::string verboseSrcAddr();
    std::string verboseType();
    std::string verboseAll();
};


#endif