#ifndef __CUTE_L4_PACKET__
#define __CUTE_L4_PACKET__



class L4_Packet {

public:
    L4_Packet();
    virtual ~L4_Packet();

    bool parseData(char *, int);

};



#endif