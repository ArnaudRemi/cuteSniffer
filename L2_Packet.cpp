#include "L2_Packet.h"

L2_Packet::L2_Packet() {
    this->type = OTHER;

    this->head = new ethernet_header;
    this->content = new L3_Packet;
}

L2_Packet::~L2_Packet() {
    delete this->head;
    delete this->content;
}

void L2_Packet::parseData(char *data, int size){
    this->setData(data);
    this->setSize(size);

    this->parseData();
}

void L2_Packet::parseData(){
    int i = 0;
    int j;
    char *tmp = (char *) this->head;
    int proto_values[] = L3_PROTO_VALUE;

    for (j=0;j<14;j++)
        tmp[j] = this->data[j];

    while (proto_values[i] != 0 && proto_values[i] != this->head->ether_type)
        ++i;
    this->type = (L3_proto) i; // position L3_PROTO_VALUE == L3_proto


    /*for (j=0;j<6;j++)
        this->head->ether_dhost[j] = data[j];
    for (j=6;j<12;j++)
        this->head->ether_shost[j-6] = data[j];

    this->head->ether_type =

    if (data[12]==8 && data[13]==0)
        p = IPV4;
    else if (data[12]==134 && data[13]==221)
        p = IPV6;
    else if (data[12]==8 && data[13]==6)
        p = ARP;*/

    //en fonction du type creer un packet genre IPPACKET ou TCPPACKET ou ARPPACKET ou autre.
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