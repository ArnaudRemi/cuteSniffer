#ifndef __CUTE_L3_PACKET__
#define __CUTE_L3_PACKET__

#include <stdio.h>
#include <string.h>

// valeur hexa qui corespondent à l'enum L3_proto dans le header ethernet: voir ethertype http://en.wikipedia.org/wiki/EtherType
#define L3_PROTO_VALUE1 {8, 134, 8, 129, 0}
#define L3_PROTO_VALUE2 {0, 221, 6, 0, 0}



typedef enum {
    IPV4 = 0,
    IPV6,
    ARP,
    IEE8021Q,
    OTHER
} L3_proto;


class L3_Packet {

    L3_proto type;

public:
    L3_Packet();
    virtual ~L3_Packet();

    bool parseData(char *data, int size);

};


#endif