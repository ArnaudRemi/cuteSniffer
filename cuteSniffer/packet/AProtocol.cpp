/*
 * AProtocol.cpp
 *
 *  Created on: 8 déc. 2014
 *      Author: cursan_a
 */

#include "AProtocol.hh"
#include <sys/time.h>

AProtocol::AProtocol(unsigned char *buffer, int bufferSize) :
    buffer(Utils::memncpy(buffer, bufferSize)), bufferSize(bufferSize), sec(0), msec(0) {
	setTime();
}

AProtocol::AProtocol() :
    buffer(NULL), bufferSize(0), sec(0), msec(0)  {
	setTime();
}

AProtocol::~AProtocol() {
    if (this->buffer)
        free(this->buffer);
}

void AProtocol::setTime() {
	struct timeval time;
	gettimeofday(&time, NULL);
	sec = time.tv_sec;
	msec = time.tv_usec;
}

unsigned char *AProtocol::getBuffer() {
    this->actualizeBuffer();
    return this->buffer;
}
void AProtocol::setBuffer(unsigned char* buffer) {
    this->buffer = buffer;
}
int AProtocol::getBufferSize() const {
    return bufferSize;
}
void AProtocol::setBufferSize(int bufferSize) {
    this->bufferSize = bufferSize;
}
void AProtocol::actualizeBuffer() {
    if (this->bufferSize <= this->getTotalNbByteInBufferNeed()) {
        if (this->buffer)
            free(buffer);
        this->bufferSize = this->getTotalNbByteInBufferNeed();
        this->buffer = (unsigned char *) malloc(this->bufferSize);
    }
    this->setDataOnBuffer();
}

std::ostream& operator <<(std::ostream& stream, AProtocol &p)
{
    stream << p.toString();
    return stream;
}

unsigned int AProtocol::getMsec() const {
	return msec;
}

void AProtocol::setMsec(unsigned int msec) {
	this->msec = msec;
}

unsigned int AProtocol::getSec() const {
	return sec;
}

void AProtocol::setSec(unsigned int sec) {
	this->sec = sec;
}
