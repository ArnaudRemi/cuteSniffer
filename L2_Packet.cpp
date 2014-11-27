#include "L2_Packet.h"

L2_Packet::L2_Packet() {
    this->type = OTHER;

    this->head = new ethernet_header;
    this->content = NULL;
}

L2_Packet::~L2_Packet() {
    delete this->head;
    if (this->content)
        delete this->content;
}

void L2_Packet::parseData(char *data, int size){
    int i = 0;
    int j;
    //char *tmp = (char *) this->head;
    short proto_values1[] = L3_PROTO_VALUE1;
    short proto_values2[] = L3_PROTO_VALUE2;

    memcpy(this->head, data, sizeof(ethernet_header));

    while (proto_values1[i] != 0 &&
            proto_values1[i] != data[12] &&
            proto_values2[i] != data[13])
        ++i;
    this->type = (L3_proto) i; // position L3_PROTO_VALUE == L3_proto

    if (this->type == IPV4){
        std::cout << "IPV4 is here!!!" << std::endl;
        this->content = new IP_Packet();
        ((IP_Packet *)this->content)->parseData(&(data[sizeof(ethernet_header)]), size - sizeof(ethernet_header));
    }
    else if (this->type == ARP){
        std::cout << "ARP yeah yeah" << std::endl;
        this->content = new ARP_Packet();
        ((ARP_Packet *)this->content)->parseData(&(data[sizeof(ethernet_header)]), size - sizeof(ethernet_header));
    }
    else if (this->type == IPV6) {
        std::cout << "IPV6 Oh My God!" << std::endl;
        this->content = new IPV6_Packet();
        ((IPV6_Packet *)this->content)->parseData(&(data[sizeof(ethernet_header)]), size - sizeof(ethernet_header));
    }
    else
        std::cout << "not IPV4 or ARP" << std::endl;
}

char *L2_Packet::getData(){
    return this->data;
}

void L2_Packet::setData(char *data) {
    this->data = data;
}

int L2_Packet::getSize(){
    return this->size;
}

void L2_Packet::setSize(int size) {
    this->size = size;
}

L3_proto L2_Packet::getType() const {
    return this->type;
}

void L2_Packet::setType(L3_proto type) {
    this->type = type;
}