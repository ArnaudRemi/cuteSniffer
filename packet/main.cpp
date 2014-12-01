/*
 * main.cpp
 *
 *  Created on: 1 déc. 2014
 *      Author: cursan_a
 */

#include "Ethernet.hh"
#include "ARP.hh"

int main() {
	std::cout << "Simple Ethernet" << std::endl;
	Ethernet pqt;
	pqt.setEther_dhost("00:01:02:03:04:05");
	pqt.setEther_shost("99:22:33:55:af:d1");
	pqt.setEther_type('a');
	std::cout << pqt << std::endl << std::endl << std::endl << std::endl;

	std::cout << "Simple ARP (Hérité de Ethernet)" << std::endl;
	ARP pqt2;
	pqt2.setEther_dhost("00:09:17:ee:24:fa");
	pqt2.setSpa("192.168.0.17");
	pqt2.setTpa("25.182.17.28");
	std::cout << pqt2 << std::endl << std::endl << std::endl << std::endl;

	std::cout << "Ethernet transformé en ARP" << std::endl;
	Ethernet pqt3;
	pqt3.setEther_dhost("a1:b2:c3:d4:e5:f6");
	pqt3.setEther_shost("ff:ee:dd:cc:bb:aa");
	pqt3.setEther_type('z');
	std::cout << pqt3 << std::endl << std::endl;
	ARP pqt4(pqt3);
	pqt4.setSpa("192.168.0.14");
	std::cout << pqt4 << std::endl;
}
