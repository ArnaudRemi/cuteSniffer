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
 * A has a mac aa:aa:aa:aa:aa and IP 192.168.1.1
 * He communicates with B 192.168.1.254, mac bb:bb:bb:bb:bb
 * I want to intercept that. My mac is ee:dd:cc:bb:aa
 *
 * I call ManInTheMiddle(a, b) with a {aa:aa:aa:aa:aa, 192.168.1.1} (target data) and b {bb:bb:bb:bb:bb, 192.168.1.254} (target2 data) and c {ee:dd:cc:bb:aa} (replacement mac)
 * Then I call buildArpPacket and I can get my ARP packet by using getPacket(), first one is for a and second one for b.
*/

typedef struct s_network_data {
        std::string mac;
        std::string ip;
} t_network_data;

class ManInTheMiddle {
private:
    t_network_data  _target;
    t_network_data  _target2;

    std::string     _mac;

    ARP<Ethernet>   _packet[2];

public:
    ManInTheMiddle(t_network_data, t_network_data, std::string);
    ~ManInTheMiddle();

    void    setTargetData(t_network_data);
    void    setTarget2Data(t_network_data);
    void    setMac(std::string);
    void    buildArpPacket();

    ARP<Ethernet>   *getPacket();
};

#endif // CUTESNIFFER2_TOOLS_MANINTHEMIDDLE_HH

