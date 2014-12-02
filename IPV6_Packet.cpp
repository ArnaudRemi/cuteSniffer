#include "IPV6_Packet.h"
#include <sstream>

IPV6_Packet::IPV6_Packet() {
    this->head = new ipv6_header;
    this->content = NULL;
}

IPV6_Packet::~IPV6_Packet() {
    delete this->head;
    if (this->content)
        delete this->content;
}

bool IPV6_Packet::parse_data(char *data, int size) {
    if (size < sizeof(ipv6_header)) {
        std::cout << "invalid IPV6 size" << std::endl;
        return false;
    }

    memcpy(this->head, data, sizeof(ipv6_header));

    char paylen = this->head->ip6_infos.un1.plen;
    char nexthead = this->head->ip6_infos.un1.next_head;

    if (paylen == 0)
        std::cout << " JUMBOGRAM " << std::endl;
    else if (paylen != size - sizeof(ipv6_header)) {
        std::cout << "payload length problem:" << std::endl;
        std::cout << "plen == " << paylen << "  | size == " << size - sizeof(ipv6_header) << std::endl;
        return false;
    }

    verboseAll();

    if (nexthead == IPPROTO_TCP) {
        std::cout << "TCP packet" << std::endl;
        this->content = new TCP_Packet;
        ((TCP_Packet *)this->content)->parseData(&(data[sizeof(ipv6_header)]), size-sizeof(ipv6_header));
    }
    else if (nexthead == IPPROTO_UDP) {
        std::cout << "UDP packet" << std::endl;
        this->content = new UDP_Packet;
        ((UDP_Packet *)this->content)->parseData(&(data[sizeof(ipv6_header)]), size-sizeof(ipv6_header));
    }
    else if (nexthead == IPPROTO_ICMP){
        std::cout << "ICMPV6 packet" << std::endl;
        this->content = new ICMPV6_Packet;
        ((ICMPV6_Packet *)this->content)->parseData(&(data[sizeof(ipv6_header)]), size-sizeof(ipv6_header));
    }
    else
        std::cout << "other protocol" << std::endl;

    return true;
}

std::string IPV6_Packet::verboseDestAddr(){
    std::stringstream ss;
    for(int i=0;i<16;i+=2){
        ss << std::hex << (int) this->head->ip6_dest.s6_addr[i] << (int) this->head->ip6_dest.s6_addr[i+1];
        if (i < 14)
            ss << ":";
    }
    return ss.str();
}

std::string IPV6_Packet::verboseSrcAddr(){
    std::stringstream ss;
    for(int i=0;i<16;i+=2){
        ss << std::hex << (int) this->head->ip6_src.s6_addr[i] << (int) this->head->ip6_src.s6_addr[i+1];
        if (i < 14)
            ss << ":";
    }
    return ss.str();
}

std::string IPV6_Packet::verboseType(){
    char nexthead = this->head->ip6_infos.un1.next_head;

    if (nexthead == IPPROTO_TCP){
        return "TCP packet";
    }
    else if (nexthead == IPPROTO_UDP){
        return "UDP packet";
    }
    else if (nexthead == IPPROTO_ICMP){
        return "ICMP packet";
    }
    return "other protocol";
}

std::string IPV6_Packet::verboseAll(){
    std::string str = "Destination address : ";
    str += verboseDestAddr();
    str += "\nSource address : ";
    str+= verboseSrcAddr();
    str+="\nProtocol : ";
    str+= verboseType();
    return str;
}