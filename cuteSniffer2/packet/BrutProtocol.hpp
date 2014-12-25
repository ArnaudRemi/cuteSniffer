/*
 * BrutProtocol.hh
 *
 *  Created on: 7 déc. 2014
 *      Author: cursan_a
 */

#ifndef PACKET_BRUTPROTOCOL_HH_
#define PACKET_BRUTPROTOCOL_HH_

#include <sstream>
#include <cstring>
#include <iostream>
#include "AProtocol.hh"

template<class T>
class BrutProtocol: public ASubProtocol<T> {
private:
	char *brut;
	int brutSize;
public:
	BrutProtocol() :
			brut(NULL), brutSize(0) {

	}

	BrutProtocol(char* data, int dataSize) :
			ASubProtocol<T>(data, dataSize), brut(NULL), brutSize(0) {
		if (dataSize > T::getTotalSize()) {
			this->brutSize = dataSize - T::getTotalSize();
			data = Utils::memncpy(data + T::getTotalSize(), this->brutSize);
		}
	}

	BrutProtocol(T &pqt) :
			brut(NULL), brutSize(0) {
		new (this) BrutProtocol(pqt.getBuffer(), pqt.getBufferSize());
	}

	virtual ~BrutProtocol() {
	}

	int getTotalSize() {
		return T::getTotalSize() + brutSize;
	}

	virtual void setDataOnBuffer() {
		T::setDataOnBuffer();
		memcpy(this->buffer + T::getTotalSize(), this->brut, brutSize);
	}

	virtual std::string toString() {
		std::ostringstream stream;
		stream << T::toString() << "BrutProtocol(" << this->getTotalSize()
				<< ")=[Size: " << this->brutSize << "]"
				<< std::endl;
		return stream.str();
	}

	char* getBrut() const {
		return brut;
	}

	void setBrut(char* brut) {
		this->brut = brut;
	}

	int getBrutSize() const {
		return brutSize;
	}

	void setBrutSize(int brutSize) {
		this->brutSize = brutSize;
	}
};

#endif /* PACKET_BRUTPROTOCOL_HH_ */
