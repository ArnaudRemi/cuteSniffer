#include "ARP_Packet.h"

ARP_Packet::ARP_Packet(){
    this->head = new arp_header;
}

ARP_Packet::~ARP_Packet(){
    delete this->head;
}

bool ARP_Packet::parseData(char *data, int size){

    if (size != sizeof(arp_header)){
        std::cout << "invalid arp size" << std::endl;
//        return false;
    }
    memcpy(this->head, data, sizeof(arp_header));

    verboseAll();

    return true;
}

std::string ARP_Packet::verboseDestMacAddr(){
    std::stringstream ss;
    for(int i=0;i<6;i++){
        ss << std::hex << (int) this->head->tha[i];
        if (i < 5)
            ss << ":";
    }
    return ss.str();
}
std::string ARP_Packet::verboseSrcMacAddr(){
    std::stringstream ss;
    for(int i=0;i<6;i++){
        ss << std::hex << (int) this->head->sha[i];
        if (i < 5)
            ss << ":";
    }
    return ss.str();
}

std::string ARP_Packet::verboseDestIpAddr(){
    std::stringstream ss;
    for(int i=0;i<4;i++){
        ss << std::dec << (int) this->head->tpa[i];
        if (i < 3)
            ss << ".";
    }
    return ss.str();
}

std::string ARP_Packet::verboseSrcIpAddr(){
    std::stringstream ss;
    for(int i=0;i<4;i++){
        ss << std::dec << (int) this->head->spa[i];
        if (i < 3)
            ss << ".";
    }
    return ss.str();
}

std::string ARP_Packet::verboseAll(){
    std::string str = "Destination MAC address : ";
    str += verboseDestMacAddr();
    str += "\nSource MAC address : ";
    str+= verboseSrcMacAddr();
    str += "Destination IPaddress : ";
    str += verboseDestIpAddr();
    str += "\nSource IP address : ";
    str+= verboseSrcIpAddr();
    return str;
}