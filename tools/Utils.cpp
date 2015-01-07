#include "Utils.hh"

#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>

unsigned char *Utils::convertMACToByte(std::string mac) {
    unsigned char *ret;
    std::size_t save = 0;
    std::size_t pos;
    int convert;

    if ((ret = (unsigned char *) malloc(sizeof(unsigned char) * 6)) == NULL)
        return (NULL);
    for (int i = 0; i <= 5; ++i) {
        if ((pos = mac.find(":", save)) == std::string::npos)
            pos = mac.size();
        std::string hex = mac.substr(save, pos - save);
        std::stringstream ss;
        ss << std::hex << hex;
        ss >> convert;
        ret[i] = (unsigned char) convert;
        save = pos + 1;
    }
    return ret;
}

std::string Utils::convertByteToMAC(unsigned char *byte) {
    std::string ret;

    for (int i = 0; i <= 5; ++i) {
        std::stringstream ss;
        ss << std::hex << std::setfill('0') << std::setw(2) << (int) byte[i];
        if (i)
            ret += ":";
        ret += ss.str();
    }
    return ret;
}

unsigned char* Utils::convertIPToByte(std::string ip) {
    unsigned char *ret;
    std::size_t save = 0;
    std::size_t pos;
    int convert;

    if ((ret = (unsigned char *) malloc(sizeof(unsigned char) * 4)) == NULL)
        return (NULL);
    for (int i = 0; i <= 3; ++i) {
        if ((pos = ip.find(".", save)) == std::string::npos)
            pos = ip.size();
        std::string dec = ip.substr(save, pos - save);
        std::stringstream ss;
        ss << dec;
        ss >> convert;
        ret[i] = (unsigned char) convert;
        save = pos + 1;
    }
    return ret;
}

struct in_addr Utils::convertIPtoIn_addr(std::string ip) {
    struct in_addr ret;
    unsigned char *ptr = (unsigned char *)&(ret.s_addr);
    std::size_t save = 0;
    std::size_t pos;
    int convert;

    for (int i = 0; i <= 3; ++i) {
        if ((pos = ip.find(".", save)) == std::string::npos)
            pos = ip.size();
        std::string dec = ip.substr(save, pos - save);
        std::stringstream ss;
        ss << dec;
        ss >> convert;
        ptr[i] = (unsigned char) convert;
        save = pos + 1;
    }
    return ret;
}

std::string Utils::convertByteToIP(unsigned char* byte) {
    std::string ret;

    for (int i = 0; i <= 3; ++i) {
        std::stringstream ss;
        ss << (int) byte[i];
        if (i)
            ret += ".";
        ret += ss.str();
    }
    return ret;
}

std::string Utils::convertIn_addrToIP(struct in_addr in_addr) {
    std::string ret;
    unsigned char *ptr = (unsigned char *)&(in_addr.s_addr);

    for (int i = 0; i <= 3; ++i) {
        std::stringstream ss;
        ss << (int) ptr[i];
        if (i)
            ret += ".";
        ret += ss.str();
    }
    return ret;
}

unsigned char *Utils::memncpy(unsigned char *data, int size) {
    if (!data)
        return (NULL);
    unsigned char *ret;
    if ((ret = (unsigned char *)malloc(size)) == NULL)
        return NULL;
    memcpy(ret, data, size);
    return ret;
}

struct in6_addr Utils::convertIPV6toIn6_addr(std::string ipv6) {
    struct in6_addr ret;
    unsigned char *ptr = (unsigned char *)&(ret.s6_addr);
    std::size_t save = 0;
    std::size_t pos;
    int convert;

    for (int i = 0; i < 8; ++i) {
        if ((pos = ipv6.find(":", save)) == std::string::npos)
            pos = ipv6.size();
        std::string hex1 = ipv6.substr(save, (pos - 2) - save);
        std::string hex2 = ipv6.substr(save + 2, pos - (save + 2));
        std::stringstream ss;
        ss << std::hex << hex1;
        ss >> convert;
        ptr[i * 2] = (unsigned char) convert;
        std::stringstream ss2;
        ss2 << std::hex << hex2;
        ss2 >> convert;
        ptr[i * 2 + 1] = (unsigned char) convert;
        save = pos + 1;
    }
    return ret;
}

std::string Utils::convertIn6_addrToIPV6(struct in6_addr in6_addr) {
    std::string ret;
    unsigned char *ptr = (unsigned char *)&(in6_addr.s6_addr);

    for (int i = 0; i < 16; ++i) {
        std::stringstream ss;
        ss << std::hex << std::setfill('0') << std::setw(2) << (int) ptr[i];
        if (i && !(i % 2))
            ret += ":";
        ret += ss.str();
    }
    return ret;
}

std::string Utils::convertBrutDataToString(unsigned char *data, int len) {
    std::string ret;

    for (int i = 0; i < len; i++) {
        if(data[i] < 32 || data[i] > 126 || data[i] == '\\')
            //ret += '\\' + std::to_string((int)data[i]) + '\\';
            ret += '.';
        else
            ret += data[i];
    }
    return ret;
}

unsigned char *Utils::convertStringToBrutData(std::string stdstr, int *len) {
    const char *str = stdstr.c_str();
    int i = 0;
    *len = 0;
    while (str[i]) {
        if (str[i] == '\\'){
            i++;
            while (str[i] && str[i] != '\\')
                i++;
            if (!str[i])
                return NULL;
        }
        i++;
        (*len)++;
    }
    unsigned char *ret;
    if ((ret = (unsigned char*) malloc(*len)) == NULL)
        return NULL;
    i = 0;
    int j = 0;
    while (str[i]) {
        if (str[i] == '\\'){
            i++;
            std::string nbStr;
            while (str[i] != '\\')
                nbStr += str[i++];
            int nb;
            std::istringstream(nbStr) >> nb;
            ret[j] = (unsigned char)nb;
        } else {
            ret[j] = str[i];
        }
        i++;
        j++;
    }
    return ret;
}

static void modifyValue(unsigned char *buffer, int *lenAddr, std::string tochange, std::string value) {
    int len = *lenAddr;
    const char* toFind = tochange.c_str();
    char* tmp;
    const char* cvalue = value.c_str();
    unsigned char* found = std::search(buffer, buffer + len, toFind, toFind + strlen(toFind));

    if(found < buffer + len) {

        if (tochange.size() != value.size()) {
            int newsize = len + (tochange.size() - value.size());
            memcpy(tmp, buffer, len);
            realloc(buffer, newsize);
            if (tochange.size() < value.size()) {
                for (int i=0; found+i<found+tochange.size() && found+i<buffer+newsize; i++) {
                    found[i] = cvalue[i];
                }
                for (int i=tochange.size(); found+i<found+value.size() && found+i<buffer+newsize; i++) {
                    found[i + (tochange.size()-value.size())] = tmp[i];
                    found[i] = cvalue[i];
                }
            }
            else {
                for (int i=0; found+i<found+value.size() && found+i<buffer+newsize; i++) {
                    found[i] = cvalue[i];
                }
                for (int i=value.size(); found+i<found+tochange.size() && found+i<buffer+newsize; i++) {
                    found[i] = tmp[i + (value.size()-tochange.size())];
                }
            }
            *lenAddr = newsize;
        }
        else {
            for (int i=0; found+i<found+tochange.size() && found+i<buffer+len; i++) {
                found[i] = cvalue[i];
            }
        }

        Utils::modifyValue(buffer, lenAddr, tochange, value);
    }
}
