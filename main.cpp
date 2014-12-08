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
#include "IPV6.hh"
#include "TCP.hh"
#include "UDP.hh"
#include "BrutProtocol.hh"
#include "ICMP.hh"
#include "ICMPV6.hh"
#include "RawSocket.hh"

int main() {
	std::cout << "###########################################" << std::endl;
	std::cout << "Simple Ethernet" << std::endl;
	std::cout << "###########################################" << std::endl;
	Ethernet pqt;
	pqt.setEther_dhost("00:01:02:03:04:05");
	pqt.setEther_shost("99:22:33:55:af:d1");
	pqt.setEther_type('a');
	std::cout << pqt << std::endl << std::endl << std::endl;

	std::cout << "###########################################" << std::endl;
	std::cout << "Simple ARP (Hérité de Ethernet)" << std::endl;
	std::cout << "###########################################" << std::endl;
	ARP<Ethernet> pqt2;
	pqt2.setEther_dhost("00:09:17:ee:24:fa");
	pqt2.setSpa("192.168.0.17");
	pqt2.setTpa("25.182.17.28");
	std::cout << pqt2 << std::endl << std::endl << std::endl;

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
	std::cout << pqt4 << std::endl << std::endl << std::endl;

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
	std::cout << pqt6 << std::endl;

	std::cout << "###########################################" << std::endl;
	std::cout << "Simple UDP (Hérité de IP (Hérité de Ethernet))" << std::endl;
	std::cout << "###########################################" << std::endl;
	UDP<IP<Ethernet> > pqt7;
	pqt7.setEther_dhost("ff:aa:ee:bb:dd:cc");
	pqt7.setIpDst("10.100.200.255");
	pqt7.setUdphDestport(10000);
	std::cout << pqt7 << std::endl;

	std::cout << "###########################################" << std::endl;
	std::cout << "UDP transformé en Ethernet puis en UDP" << std::endl;
	std::cout << "###########################################" << std::endl;
	UDP<IP<Ethernet> > pqt8;
	pqt8.setEther_dhost("12:ab:34:cd:56:ef");
	pqt8.setIpDst("255.254.253.252");
	pqt8.setUdphDestport(666);
	std::cout << pqt8 << std::endl << std::endl;
	Ethernet pqt9(pqt8);
	std::cout << pqt9 << std::endl << std::endl;
	IP<Ethernet> pqt10(pqt9);
	std::cout << pqt10 << std::endl << std::endl;
	UDP<IP<Ethernet> > pqt11(pqt10);
	IP<Ethernet> toto;
	std::cout << pqt11 << std::endl << std::endl;

	std::cout << "###########################################" << std::endl;
	std::cout << "Simple IPV6 (Hérité de Ethernet)" << std::endl;
	std::cout << "###########################################" << std::endl;
	IPV6<Ethernet> pqt12;
	pqt12.setIp6Src("2001:0db8:0000:85a3:0000:0000:ac1f:8001");
	pqt12.setIp6Dest("8000:0000:0000:0000:0123:4567:89AB:CDEF");
	std::cout << pqt12 << std::endl << std::endl;

	std::cout << "###########################################" << std::endl;
	std::cout
			<< "Simple BrutProtocol (Hérité de TCP(Hérité de IP(Hérité de Ethernet)))"
			<< std::endl;
	std::cout << "###########################################" << std::endl;
	BrutProtocol<TCP<IP<Ethernet> > > pqt13;
	pqt13.setBrutSize(20);
	std::cout << pqt13 << std::endl << std::endl;

	std::cout << "###########################################" << std::endl;
	std::cout << "Simple ICMP (Hérité de IP(Hérité de Ethernet))" << std::endl;
	std::cout << "###########################################" << std::endl;
	ICMP<IP<Ethernet> > pqt14;
	pqt14.setType('a');
	std::cout << pqt14 << std::endl << std::endl;

	std::cout << "###########################################" << std::endl;
	std::cout << "Simple ICMPV6 (Hérité de IP(Hérité de Ethernet))"
			<< std::endl;
	std::cout << "###########################################" << std::endl;
	ICMPV6<IP<Ethernet> > pqt15;
	pqt15.setType('b');
	std::cout << pqt15 << std::endl << std::endl;

	std::cout << "###########################################" << std::endl;
	std::cout << "Réception de packet" << std::endl;
	std::cout << "###########################################" << std::endl;
	RawSocket socket;
	socket.goPromiscious("eth0");
	Ethernet *testSocket = socket.getPacket();
	std::cout << *testSocket << std::endl;
}

// L2 : Ethernet
// L3 : ARP, IP, IPV6
// L4 : ICMP, ICMPV6, TCP, UDP
