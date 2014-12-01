#pragma once

#include <string>

class Utils {
public:
	static unsigned char *convertMACToByte(std::string mac);
	static std::string convertByteToMAC(unsigned char *byte);
	static unsigned char *convertIPToByte(std::string ip);
	static std::string convertByteToIP(unsigned char* byte);

};
