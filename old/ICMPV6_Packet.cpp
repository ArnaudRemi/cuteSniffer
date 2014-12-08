#include "ICMPV6_Packet.h"

ICMPV6_Packet::ICMPV6_Packet(){
    this->head = new icmpv6_header;
}

ICMPV6_Packet::~ICMPV6_Packet(){
    delete this->head;
}

bool ICMPV6_Packet::parseData(char * data, int size){
    if (size != sizeof(icmpv6_header))
        std::cout << "invalid ICMPV6 size" << std::endl;

    memcpy(this->head, data, sizeof(icmpv6_header));

//    this->content =

    std::cout << "TODO" << std::endl;
}