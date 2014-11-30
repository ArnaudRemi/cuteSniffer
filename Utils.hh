#pragma once

#include <string>

class Utils {
public:
	static unsigned char *convertMacToByte(std::string mac);
	static std::string convertByteToMac(unsigned char *byte);
};