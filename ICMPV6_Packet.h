#ifndef __CUTE_ICMPV6_PACKET__
#define __CUTE_ICMPV6_PACKET__

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "L4_Packet.h"

typedef struct s_icmpv6 {
    unsigned char type;
    unsigned char code;
    unsigned short checksum;
}icmpv6_header;

class ICMPV6_Packet : public L4_Packet {

    icmpv6_header *head;
    char *content;

public:

    ICMPV6_Packet();
    ~ICMPV6_Packet();

    bool parseData(char * data, int size);
};

#endif