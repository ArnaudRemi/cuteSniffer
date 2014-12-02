#include <iostream>
#include <sstream>
#include "L2_Packet.h"

L2_Packet::L2_Packet() {
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

    //Ether type is reversed... dafuuu?!
    char tmp12 = data[12];
    data[12] = data[13];
    data[13] = tmp12;

    memcpy(this->head, data, sizeof(ethernet_header));

    std::cout << verboseAll() << std::endl;

    if (this->head->ether_type == ETH_P_IP){
        std::cout << "IPV4 is here!!!" << std::endl;
        this->content = new IP_Packet();
        ((IP_Packet *)this->content)->parseData(&(data[sizeof(ethernet_header)]), size - sizeof(ethernet_header));
    }
    else if (this->head->ether_type == ETH_P_ARP) {
        std::cout << "ARP yeah yeah" << std::endl;
        this->content = new ARP_Packet();
        ((ARP_Packet *)this->content)->parseData(&(data[sizeof(ethernet_header)]), size - sizeof(ethernet_header));
    }
    else if (this->head->ether_type == ETH_P_IPV6) {
        std::cout << "IPV6 Oh My God!" << std::endl;
        this->content = new IPV6_Packet();
        ((IPV6_Packet *)this->content)->parseData(&(data[sizeof(ethernet_header)]), size - sizeof(ethernet_header));
    }
    else
        std::cout << "other protocol" << std::endl;


}

std::string L2_Packet::verboseDestAddress(){
    std::stringstream ss;
    for(int i=0;i<6;i++){
        ss << std::hex << (int) this->head->ether_dhost[i];
        if (i < 5)
            ss << ":";
    }
    return ss.str();
}

std::string L2_Packet::verboseSrcAddress(){
    std::stringstream ss;
    for(int i=0;i<6;i++){
        ss << std::hex << (int) this->head->ether_shost[i];
        if (i < 5)
            ss << ":";
    }
    return ss.str();
}

std::string L2_Packet::verboseType(){
    if (this->head->ether_type == ETH_P_IP)
            return "IPV4";
    else if  (this->head->ether_type == ETH_P_ARP)
        return "ARP";
    else if  (this->head->ether_type == ETH_P_IPV6)
        return "IPV6";
    return "other protocol";
}

std::string L2_Packet::verboseAll(){
    std::string str = "Destination address : ";
    str += verboseDestAddress();
    str += "\nSource address : ";
    str+= verboseSrcAddress();
    str+="\nEtherType : ";
    str+= verboseType();
    return str;
}


// GET/SET
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
