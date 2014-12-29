#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include "MainView.hh"
#include "PcapHandler.hh"
#include "Ethernet.hh"
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
}

// L2 : Ethernet
// L3 : ARP, IP, IPV6
// L4 : ICMP, ICMPV6, TCP, UDP
