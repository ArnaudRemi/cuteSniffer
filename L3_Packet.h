#ifndef __CUTE_L3_PACKET__
#define __CUTE_L3_PACKET__

#include <stdio.h>
#include <string.h>

class L3_Packet {

    L3_proto type;

public:
    L3_Packet();
    virtual ~L3_Packet();

    bool parseData(char *data, int size);

};


#endif