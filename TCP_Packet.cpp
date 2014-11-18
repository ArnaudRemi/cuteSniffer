#include "TCP_Packet.h"

TCP_Packet::TCP_Packet(){
    this->head = new tcp_header;
    this->content = NULL;
}

TCP_Packet::~TCP_Packet(){
    delete this->head;
    if(this->content)
        delete this->content;
}

bool TCP_Packet::parseData(char *data, int size) {
    int finalsize;

    if (size < 20) {
        std::cout << "invalid TCP data" << std::endl;
        return false;
    }
    memcpy(this->head, data, sizeof(tcp_header));

    finalsize = TH_OFF(this->head)*4;
    if (finalsize < 20) {
        std::cout << "invalid TCP header" << std::endl;
        return false;
    }
    else if (finalsize > 20){
        //memcpy(this->head, data, finalsize);
        std::cout << "TCP packet with option" << std::endl;
    }

    std::cout << "payload == " << &(data[finalsize]) << std::endl;
    return true;
}