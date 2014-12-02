/*
 * Protocole.hh
 *
 *  Created on: 2 déc. 2014
 *      Author: cursan_a
 */

#ifndef PACKET_APROTOCOL_HH_
#define PACKET_APROTOCOL_HH_

#include <type_traits>

class AProtocol {
protected:
	char* buffer;
	int bufferSize;
public:
	AProtocol(char *buffer, int bufferSize) :
			buffer(buffer), bufferSize(bufferSize) {

	}
	AProtocol() : buffer(NULL), bufferSize(0) {}
	virtual ~AProtocol() {
	}
	char* getBuffer() {
		if (buffer == NULL)
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
	virtual int getTotalSize() = 0;
	virtual std::string toString() = 0;
	void actualizeBuffer() {
		this->buffer = (char *)malloc(sizeof(this->getTotalSize()));
		this->bufferSize = this->getTotalSize();
		this->setDataOnBuffer();
	}
	virtual void setDataOnBuffer() = 0;
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
};

#endif /* PACKET_APROTOCOL_HH_ */
