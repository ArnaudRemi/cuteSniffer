#include "IPV6_Packet.h"

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

    if (size > sizeof(ipv6_header)) {
        //fill content with new L4_Packet children
        //parse data
    }

    return true;
}
