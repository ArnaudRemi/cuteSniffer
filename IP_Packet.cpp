#include "IP_Packet.h"

IP_Packet::IP_Packet(){
    this->head = new ip_header;
    this->content = NULL;
}

IP_Packet::~IP_Packet() {
    delete this->head;
    if (this->content)
        delete this->content;
}

bool IP_Packet::parseData(char *data, int size) {
    int finalsize;

    if (size < 20) {
        std::cout << "invalid IP data" << std::endl;
        return false;
    }

    memcpy(this->head, data, sizeof(ip_header));

    finalsize = IP_HL(this->head)*4;
    if (finalsize < 20) {
        std::cout << "invalid IP header" << std::endl;
        return false;
    }
    else if (finalsize > 20){
        std::cout << "IP header with options" << std::endl;
//        memcpy(this->head, data, finalsize);
    }

    std::cout << "parse IP OK!" << std::endl;

    if (this->head->ip_p == IPPROTO_TCP){
        this->content = new TCP_Packet;
        ((TCP_Packet *)this->content)->parseData(&(data[finalsize]), size-finalsize);
    }
    //IPPROTO_UDP IPPROTO_ICMP IPPROTO_IP

    return true;
}