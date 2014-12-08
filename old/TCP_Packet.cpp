#include "TCP_Packet.h"
#include <sstream>
#include <iomanip>

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

    this->contentsize = size-finalsize;
    this->content = new char[contentsize];
    if (this->contentsize  > 0)
        memcpy(this->content, &(data[finalsize]), this->contentsize);

    std::cout << verboseAll() << std::endl;

    if (size - finalsize > 0)
        std::cout << "payload == " << &(data[finalsize]) << std::endl;
    return true;
}

std::string TCP_Packet::verboseSrcPort(){
    std::stringstream ss;
    ss << std::dec << (int) this->head->th_sport;
    return ss.str();
}

std::string TCP_Packet::verboseDestPort(){
    std::stringstream ss;
    ss << std::dec << (int) this->head->th_dport;
    return ss.str();
}

std::string TCP_Packet::verbosePayload() {

    return this->content;
}

std::string TCP_Packet::verbosePayloadHexa() {
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

std::string TCP_Packet::verboseAll() {
    std::string str = "Destination Port : ";
    str += verboseDestPort();
    str += "\nSource Port : ";
    str+= verboseSrcPort();
    str+= "\nPayload Hexa: ";
    str+= verbosePayloadHexa();
    return str;
}