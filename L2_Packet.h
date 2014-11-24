#ifndef __CUTE_L2_PACKET__
#define __CUTE_L2_PACKET__

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>

#include "L3_Packet.h"
#include "IP_Packet.h"
#include "ARP_Packet.h"

typedef struct s_ethernet {
    unsigned char  ether_dhost[6];    /* destination host address */
    unsigned char  ether_shost[6];    /* source host address */
    unsigned short ether_type;        /* IP? ARP? RARP? etc */
} ethernet_header;

class L2_Packet {

    L3_proto type;
    char *data;
    int size;
    ethernet_header *head;

    L3_Packet *content;

public:
    L2_Packet();
    virtual ~L2_Packet();

    void parseData(char *data, int size);
    void parseData();

    char *getData();
    void setData(char *data);

    int getSize();
    void setSize(int size);

    L3_proto getType() const;
    void setType(L3_proto type);


};

#endif