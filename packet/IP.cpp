/*
 * IP.cpp
 *
 *  Created on: 2 déc. 2014
 *      Author: cursan_a
 */

#include "IP.hh"

struct in_addr IP::getIpDst() const {
	return header.ip_dst;
}

void IP::setIpDst(struct in_addr ipDst) {
	header.ip_dst = ipDst;
}

unsigned short IP::getIpId() const {
	return header.ip_id;
}

void IP::setIpId(unsigned short ipId) {
	header.ip_id = ipId;
}

unsigned short IP::getIpLen() const {
	return header.ip_len;
}

void IP::setIpLen(unsigned short ipLen) {
	header.ip_len = ipLen;
}

unsigned short IP::getIpOff() const {
	return header.ip_off;
}

void IP::setIpOff(unsigned short ipOff) {
	header.ip_off = ipOff;
}

unsigned char IP::getIpP() const {
	return header.ip_p;
}

void IP::setIpP(unsigned char ipP) {
	header.ip_p = ipP;
}

struct in_addr IP::getIpSrc() const {
	return header.ip_src;
}

void IP::setIpSrc(struct in_addr ipSrc) {
	header.ip_src = ipSrc;
}

unsigned short IP::getIpSum() const {
	return header.ip_sum;
}

void IP::setIpSum(unsigned short ipSum) {
	header.ip_sum = ipSum;
}

unsigned char IP::getIpTos() const {
	return header.ip_tos;
}

void IP::setIpTos(unsigned char ipTos) {
	header.ip_tos = ipTos;
}

unsigned char IP::getIpTtl() const {
	return header.ip_ttl;
}

void IP::setIpTtl(unsigned char ipTtl) {
	header.ip_ttl = ipTtl;
}

unsigned char IP::getIpVhl() const {
	return header.ip_vhl;
}

void IP::setIpVhl(unsigned char ipVhl) {
	header.ip_vhl = ipVhl;
}
