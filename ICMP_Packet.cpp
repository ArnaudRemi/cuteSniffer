#include "ICMP_Packet.h"

ICMP_Packet::ICMP_Packet(){
    this->head = new icmp_header;
}

ICMP_Packet::~ICMP_Packet(){
    delete this->head;
}

bool ICMP_Packet::parseData(char * data, int size){
    if (size != sizeof(icmp_header))
        std::cout << "invalid icmp size" << std::endl;

    memcpy(this->head, data, sizeof(icmp_header));
}

