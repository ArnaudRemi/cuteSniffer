#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include "Utils.hh"


unsigned char			*Utils::convertMacToByte(std::string mac) {
	unsigned char		*ret;
	std::size_t 		save = 0;
	std::size_t 		pos;
	int 				convert;

	if ((ret = (unsigned char *)malloc(sizeof(unsigned char) * 6)) == NULL)
		return (NULL);
	for (int i = 0; i <= 5; ++i) {
		if((pos = mac.find(":", save)) == std::string::npos)
			pos = mac.size();
		std::string hex = mac.substr(save, pos - save);
		std::stringstream ss;
		ss << std::hex << hex;
		ss >> convert;
		ret[i] = (unsigned char)convert;
		save = pos + 1;
	}
	return ret;
}

std::string 			Utils::convertByteToMac(unsigned char *byte) {
	std::string 		ret;
 	
	for (int i = 0; i <= 5; ++i) {
		std::stringstream 	ss;
		ss << std::hex << std::setfill('0') << std::setw(2) << (int)byte[i];
		if (i)
			ret += ":";
		ret += ss.str();
	}
	return ret;
}