#ifndef __CUTE_L3_PACKET__
#define __CUTE_L3_PACKET__

// valeur hexa qui corespondent à l'enum L3_proto dans le header ethernet: voir ethertype http://en.wikipedia.org/wiki/EtherType
#define L3_PROTO_VALUE {0x0800, 0x86DD, 0x0806, 0x8100, 0}

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

    void parseData(char *data, int size);
    void parseData();

};


#endif