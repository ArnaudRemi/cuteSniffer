#ifndef __CUTE_ICMPV6_PACKET__
#define __CUTE_ICMPV6_PACKET__

typedef struct s_icmpv6 {
    unsigned char type;
    unsigned char code;
    unsigned short checksum;
}icmpv6_header;

class ICMPV6 : public L4_Packet {

    icmpv6_header *head;

public:

    ICMPV6_Packet();
    ~ICMPV6_Packet();

    bool parseData(char * data, int size);
};
#endif