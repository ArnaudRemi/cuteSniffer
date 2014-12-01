#ifndef __CUTE_TCP_PACKET__
#define __CUTE_TCP_PACKET__

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include "L4_Packet.h"

typedef struct s_tcp {
    unsigned short th_sport;               /* source port */
    unsigned short th_dport;               /* destination port */
    unsigned int th_seq;                 /* sequence number */
    unsigned int th_ack;                 /* acknowledgement number */
    unsigned char th_off;               /* data offset, rsvd */
#define TH_OFF(th)      (((th)->th_off & 0xf0) >> 4)
    unsigned char th_flags;
#define TH_FIN  0x01
#define TH_SYN  0x02
#define TH_RST  0x04
#define TH_PUSH 0x08
#define TH_ACK  0x10
#define TH_URG  0x20
#define TH_ECE  0x40
#define TH_CWR  0x80
#define TH_FLAGS        (TH_FIN|TH_SYN|TH_RST|TH_ACK|TH_URG|TH_ECE|TH_CWR)
    unsigned short th_win;                 /* window */
    unsigned short th_sum;                 /* checksum */
    unsigned short th_urp;                 /* urgent pointer */
} tcp_header;

class TCP_Packet : public L4_Packet {

    tcp_header *head;
    char *content;
    int contentsize;

public:
    TCP_Packet();
    ~TCP_Packet();

    bool parseData(char *data, int size);

    std::string verboseSrcPort();
    std::string verboseDestPort();
    std::string verbosePayload();
    std::string verbosePayloadHexa();
    std::string verboseAll();
};

#endif