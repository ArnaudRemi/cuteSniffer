#ifndef UTILS_HH_
#define UTILS_HH_

#include <string>
#include <netinet/in.h>

class Utils {
public:
	static unsigned char *convertMACToByte(std::string mac);
	static unsigned char *convertIPToByte(std::string ip);
	static struct in_addr convertIPtoIn_addr(std::string ip);
	static std::string convertByteToMAC(unsigned char *byte);
	static std::string convertByteToIP(unsigned char* byte);
	static std::string convertIn_addrToIP(struct in_addr);

};

#endif
