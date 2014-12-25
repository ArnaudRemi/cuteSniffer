/*
 * Protocole.hh
 *
 *  Created on: 2 déc. 2014
 *      Author: cursan_a
 */

#ifndef PACKET_APROTOCOL_HH_
#define PACKET_APROTOCOL_HH_

#include <type_traits>
#include <cstring>
#include <stdlib.h>
#include "Utils.hh"

class AProtocol {
public:
	char* buffer;
	int bufferSize;

public:
	AProtocol(char *buffer, int bufferSize) :
			buffer(Utils::memncpy(buffer, bufferSize)), bufferSize(bufferSize) {
	}

	AProtocol() :
			buffer(NULL), bufferSize(0) {
	}

	virtual ~AProtocol() {
		if (this->buffer)
			free(this->buffer);
	}

	char* getBuffer() {
		this->actualizeBuffer();
		return this->buffer;
	}
	void setBuffer(char* buffer) {
		this->buffer = buffer;
	}
	int getBufferSize() const {
		return bufferSize;
	}
	void setBufferSize(int bufferSize) {
		this->bufferSize = bufferSize;
	}
	void actualizeBuffer() {
		if (this->bufferSize <= this->getTotalSize()) {
			if (this->buffer)
				free(buffer);
			this->buffer = (char *) malloc(this->getTotalSize());
			this->bufferSize = this->getTotalSize();
		}
		this->setDataOnBuffer();
	}
	virtual int getTotalSize() = 0;
	virtual std::string toString() = 0;
	virtual void setDataOnBuffer() = 0;
	virtual std::string getSource() = 0;
	virtual std::string getDestination() = 0;
};

template<typename T>
class ASubProtocol: public T {
	static_assert(std::is_base_of<AProtocol, T>::value, "Typename T must overload IProtocol");
public:
	virtual ~ASubProtocol() {
	}
	ASubProtocol() {

	}
	ASubProtocol(char *buffer, int bufferSize) :
			T(buffer, bufferSize) {

	}
	virtual int getTotalSize() = 0;
	virtual std::string getSource() = 0;
	virtual std::string getDestination() = 0;
};


std::ostream& operator <<(std::ostream& stream, AProtocol& p);

#endif /* PACKET_APROTOCOL_HH_ */
