#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include "MainView.hh"
#include "PcapHandler.hh"
#include "Ethernet.hh"
#include "FilterData.hh"
#include "IP.hpp"


int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    MainView mainView(&engine);
    return app.exec();

	//TEST PCAP READER
	/*PcapHandler r("toto.pcap");
	std::list<Ethernet *> ret = r.getPackets();
	std::cout << "get " << ret.size() << " packets" << std::endl;
	for (Ethernet *pqt : ret) {
		IP<Ethernet> *dp = new IP<Ethernet>(*pqt);
		std::cout << *dp << std::endl;
	}
	PcapHandler t("toto2.pcap");
	t.writeFile(ret);*/

    //TEST SINGLETON FILTRE
    /*std::cout << "EtherFlag (sans modif) : " << (int)FilterData::getInstance().getEtherFlag() << std::endl;
    FilterData::getInstance().setEtherShost("10:11:12:13:14:15");
    std::cout << "EtherFlag (avec modif) : " << (int)FilterData::getInstance().getEtherFlag() << std::endl;
    if (FilterData::getInstance().getEtherFlag() & ETHER_DHOST)
    	std::cout << "ETHER_DHOST est modifié" << std::endl;
    if (FilterData::getInstance().getEtherFlag() & ETHER_SHOST)
    	std::cout << "ETHER_SHOST est modifié" << std::endl;
    if (FilterData::getInstance().getEtherFlag() & ETHER_TYPE)
    	std::cout << "ETHER_TYPE est modifié" << std::endl;
    FilterData::getInstance().setEtherShost("");
    std::cout << "EtherFlag (avec modif bis) : " << (int)FilterData::getInstance().getEtherFlag() << std::endl;
    if (FilterData::getInstance().getEtherFlag() & ETHER_DHOST)
    	std::cout << "ETHER_DHOST est modifié" << std::endl;
    if (FilterData::getInstance().getEtherFlag() & ETHER_SHOST)
    	std::cout << "ETHER_SHOST est modifié" << std::endl;
    if (FilterData::getInstance().getEtherFlag() & ETHER_TYPE)
    	std::cout << "ETHER_TYPE est modifié" << std::endl;*/
}

// L2 : Ethernet
// L3 : ARP, IP, IPV6
// L4 : ICMP, ICMPV6, TCP, UDP
