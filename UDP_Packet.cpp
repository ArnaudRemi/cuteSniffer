#include "UDP_Packet.h"

UDP_Packet::UDP_Packet(){
    this->head = new udp_header;
    this->content = NULL;
}

UDP_Packet::~UDP_Packet(){
    delete this->head;
    if (this->content)
        delete this->content;
}

bool UDP_Packet::parseData(char * data, int size){
    if (size < sizeof(udp_header)){
        std::cout << "invalid UDP size" << std::endl;
        return false;
    }

    memcpy(this->head, data, sizeof(udp_header));

    this->content = &(data[sizeof(udp_header)]);

    return true;
}
