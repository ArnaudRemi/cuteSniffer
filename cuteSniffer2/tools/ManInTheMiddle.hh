#ifndef CUTESNIFFER2_TOOLS_MANINTHEMIDDLE_HH
#define CUTESNIFFER2_TOOLS_MANINTHEMIDDLE_HH

#include    <iostream>
#include    <fstream>
#include    "Ethernet.hh"
#include    "ARP.hpp"

/*
 * Take in param 2 structure
 * One contains information about a target (Mac/IP)
 * Second contains information about what we want to replace :
 * MAC of my network card
 * IP to replace for the target
 *
 * A has a mac aa:bb:cc:dd:ee and IP 192.168.1.1
 * He communicates with B 192.168.1.254
 * I want to intercept that. My mac is ee:dd:cc:bb:aa
 *
 * I call ManInTheMiddle(a, b) with a {aa:bb:cc:dd:ee, 192.168.1.1} (target data) and b {ee:dd:cc:bb:aa, 192.168.1.254} (replacement data)
 * Then I call buildArpPacket and I can get my ARP packet by using getPacket()
*/

typedef struct s_network_data {
        std::string mac;
        std::string ip;
} t_network_data;

class ManInTheMiddle {
private:
    t_network_data  _target;
    t_network_data  _replacement;

    ARP<Ethernet>   _packet;

public:
    ManInTheMiddle(t_network_data, t_network_data);
    ~ManInTheMiddle();

    void    setTargetData(t_network_data);
    void    setReplacementData(t_network_data);
    void    buildArpPacket();

    ARP<Ethernet>   getPacket();
};

#endif // CUTESNIFFER2_TOOLS_MANINTHEMIDDLE_HH

