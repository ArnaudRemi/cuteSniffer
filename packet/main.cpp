/*
 * main.cpp
 *
 *  Created on: 1 déc. 2014
 *      Author: cursan_a
 */

#include <iostream>
#include "Ethernet.hh"
#include "ARP.hh"
#include "IP.hh"
#include "TCP.hh"

int main() {
	std::cout << "###########################################" << std::endl;
	std::cout << "Simple Ethernet" << std::endl;
	std::cout << "###########################################" << std::endl;
	Ethernet pqt;
	pqt.setEther_dhost("00:01:02:03:04:05");
	pqt.setEther_shost("99:22:33:55:af:d1");
	pqt.setEther_type('a');
	std::cout << pqt.toString() << std::endl << std::endl << std::endl
			<< std::endl;

	std::cout << "###########################################" << std::endl;
	std::cout << "Simple ARP (Hérité de Ethernet)" << std::endl;
	std::cout << "###########################################" << std::endl;
	ARP<Ethernet> pqt2;
	pqt2.setEther_dhost("00:09:17:ee:24:fa");
	pqt2.setSpa("192.168.0.17");
	pqt2.setTpa("25.182.17.28");
	std::cout << pqt2.toString() << std::endl << std::endl << std::endl
			<< std::endl;

	std::cout << "###########################################" << std::endl;
	std::cout << "Ethernet transformé en ARP" << std::endl;
	std::cout << "###########################################" << std::endl;
	Ethernet pqt3;
	pqt3.setEther_dhost("a1:b2:c3:d4:e5:f6");
	pqt3.setEther_shost("ff:ee:dd:cc:bb:aa");
	pqt3.setEther_type('z');
	std::cout << pqt3.toString() << std::endl;
	ARP<Ethernet> pqt4(pqt3);
	pqt4.setSpa("192.168.0.14");
	std::cout << pqt4.toString() << std::endl << std::endl << std::endl
			<< std::endl;

	std::cout << "###########################################" << std::endl;
	std::cout << "Simple IP (Hérité de Ethernet)" << std::endl;
	std::cout << "###########################################" << std::endl;
	IP<Ethernet> pqt5;
	pqt5.setEther_dhost("12:15:18:21:24:27");
	pqt5.setIpDst("10.10.26.97");
	std::cout << pqt5.toString() << std::endl << std::endl << std::endl;

	std::cout << "###########################################" << std::endl;
	std::cout << "Simple TCP (Hérité de IP (Hérité de Ethernet))" << std::endl;
	std::cout << "###########################################" << std::endl;
	TCP<IP<Ethernet> > pqt6;
	pqt6.setEther_dhost("ab:cd:ef:fe:dc:ba");
	pqt6.setIpDst("11.12.13.14");
	pqt6.setThDport(9091);
	std::cout << pqt6.toString() << std::endl;
}

// L2 : Ethernet
// L3 : ARP, IP, IPV6
// L4 : ICMP, ICMPV6, TCP, UDP
