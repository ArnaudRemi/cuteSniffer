#include "IP_Packet.h"
#include <sstream>

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

    finalsize = IP_HL(this->head) * 4;
    if (finalsize < 20) {
        std::cout << "invalid IP header" << std::endl;
        return false;
    }
    else if (finalsize > 20){
        std::cout << "IP header with options" << std::endl;
        memcpy(this->head, data, finalsize);
    }

    std::cout << "parse IP OK" << std::endl;
    std::cout << verboseAll() << std::endl;

    if (this->head->ip_p == IPPROTO_TCP){
        std::cout << "TCP packet" << std::endl;
        this->content = new TCP_Packet;
        ((TCP_Packet *)this->content)->parseData(&(data[finalsize]), size-finalsize);
    }
    else if (this->head->ip_p == IPPROTO_UDP){
        std::cout << "UDP packet" << std::endl;
        this->content = new UDP_Packet;
        ((UDP_Packet *)this->content)->parseData(&(data[finalsize]), size-finalsize);
    }
    else if (this->head->ip_p == IPPROTO_ICMP){
        std::cout << "ICMP packet" << std::endl;
        this->content = new ICMP_Packet;
        ((ICMP_Packet *)this->content)->parseData(&(data[finalsize]), size-finalsize);
    }
    else
        std::cout << "other packet type" << std::endl;
    //IPPROTO_UDP IPPROTO_ICMP IPPROTO_IP

    return true;
}

std::string IP_Packet::verboseDestAddr(){
    std::stringstream ss;
    for(int i=0;i<4;i++){
        ss << std::dec << (int) ((unsigned char *) &(this->head->ip_dst.s_addr))[i];
        if (i < 3)
            ss << ".";
    }
    return ss.str();
}

std::string IP_Packet::verboseSrcAddr(){
    std::stringstream ss;
    for(int i=0;i<4;i++){
        ss << std::dec << (int) ((unsigned char *) &(this->head->ip_src.s_addr))[i];
        if (i < 3)
            ss << ".";
    }
    return ss.str();
}

std::string IP_Packet::verboseType(){
    if (this->head->ip_p == IPPROTO_TCP){
        return "TCP packet";
    }
    else if (this->head->ip_p == IPPROTO_UDP){
        return "UDP packet";
    }
    else if (this->head->ip_p == IPPROTO_ICMP){
        return "ICMP packet";
    }
    return "other protocol";
}

std::string IP_Packet::verboseAll(){
    std::string str = "Destination address : ";
    str += verboseDestAddr();
    str += "\nSource address : ";
    str+= verboseSrcAddr();
    str+="\nProtocol : ";
    str+= verboseType();
    return str;
}

