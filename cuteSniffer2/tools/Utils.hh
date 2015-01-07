#ifndef UTILS_HH_
#define UTILS_HH_

#include <string>
#include <netinet/in.h>

class Ethernet;

class Utils {
public:
	static unsigned char *convertMACToByte(std::string mac);
	static unsigned char *convertIPToByte(std::string ip);
	static struct in_addr convertIPtoIn_addr(std::string ip);
	static struct in6_addr convertIPV6toIn6_addr(std::string ipv6);
	static std::string convertByteToMAC(unsigned char *byte);
	static std::string convertByteToIP(unsigned char* byte);
	static std::string convertIn_addrToIP(struct in_addr);
	static std::string convertIn6_addrToIPV6(struct in6_addr);
    static unsigned char *memncpy(unsigned char *data, int size);
    static std::string convertBrutDataToString(unsigned char *data, int len);
    static unsigned char *convertStringToBrutData(std::string stdstr, int *len);
	static void modifyValue(Ethernet *packet, std::string tochange, std::string value);
};


#endif
