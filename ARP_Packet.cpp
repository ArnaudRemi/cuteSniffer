#include "ARP_Packet.h"

ARP_Packet::ARP_Packet(){
    this->head = new arp_header;
}

ARP_Packet::~ARP_Packet(){
    delete this->head;
}

bool ARP_Packet::parse_data(char *data, int size){

    if (size != sizeof(arp_header)){
        std::cout << "invalid arp size" << std::endl;
        return false;
    }

    memcpy(this->head, data, sizeof(arp_header));
}