#ifndef __CUTE_IP_PACKET__
#define __CUTE_IP_PACKET__

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include "L3_Packet.h"
#include "L4_Packet.h"
#include "TCP_Packet.h"

// http://simplestcodings.blogspot.fr/2010/10/create-your-own-packet-sniffer-in-c.html

typedef struct s_ip {
    unsigned char  ip_vhl;                 /* version << 4 | header length >> 2 */
    unsigned char  ip_tos;                 /* type of service */
    unsigned short ip_len;                 /* total length */
    unsigned short ip_id;                  /* identification */
    unsigned short ip_off;                 /* fragment offset field */
#define IP_RF 0x8000            /* reserved fragment flag */
#define IP_DF 0x4000            /* dont fragment flag */
#define IP_MF 0x2000            /* more fragments flag */
#define IP_OFFMASK 0x1fff       /* mask for fragmenting bits */
    unsigned char  ip_ttl;                 /* time to live */
    unsigned char  ip_p;                   /* protocol */
    unsigned short ip_sum;                 /* checksum */
    struct in_addr ip_src;  /* source and dest address */
    struct in_addr ip_dst;
} ip_header;
#define IP_HL(ip)               (((ip)->ip_vhl) & 0x0f)
#define IP_V(ip)                (((ip)->ip_vhl) >> 4)

class IP_Packet : public L3_Packet{

    ip_header *head;
    L4_Packet *content;

public:
    IP_Packet();
    ~IP_Packet();

    bool parseData(char *data, int size);
};

#endif