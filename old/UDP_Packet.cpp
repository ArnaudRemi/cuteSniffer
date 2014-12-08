#include <sstream>
#include <iomanip>
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
    if (size - sizeof(udp_header) >= this->head->udph_len) {
        this->content = new char[this->head->udph_len];
        this->contentsize = this->head->udph_len;
        memcpy(this->content, &(data[sizeof(udp_header)]), this->head->udph_len);
    }

    std::cout << "payload == " << this->content << std::endl;

    return true;
}

std::string UDP_Packet::verboseSrcPort(){
    std::stringstream ss;
    ss << std::dec << (int) this->head->udph_srcport;
    return ss.str();
}

std::string UDP_Packet::verboseDestPort(){
    std::stringstream ss;
    ss << std::dec << (int) this->head->udph_destport;
    return ss.str();
}

std::string UDP_Packet::verbosePayload() {
    return this->content;
}

std::string UDP_Packet::verbosePayloadHexa() {
    std::stringstream ss;
    for (int i = 0; i < this->contentsize; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int) ((unsigned char) this->content[i]) << " ";
        if ((i && i%16 == 0) || i == this->contentsize)
            ss << "\n";
        else if (i && i%8 == 0)
            ss << " ";
    }
    return ss.str();
}

std::string UDP_Packet::verboseAll() {
    std::string str = "Destination Port : ";
    str += verboseDestPort();
    str += "\nSource Port : ";
    str+= verboseSrcPort();
    str+= "\nPayload Hexa: ";
    str+= verbosePayloadHexa();
    return str;
}

