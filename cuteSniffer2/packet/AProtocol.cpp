/*
 * AProtocol.cpp
 *
 *  Created on: 8 déc. 2014
 *      Author: cursan_a
 */

#include "AProtocol.hh"

AProtocol::AProtocol(unsigned char *buffer, int bufferSize) :
    buffer(Utils::memncpy(buffer, bufferSize)), bufferSize(bufferSize) {
}

AProtocol::AProtocol() :
    buffer(NULL), bufferSize(0) {
}

AProtocol::~AProtocol() {
    if (this->buffer)
        free(this->buffer);
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
