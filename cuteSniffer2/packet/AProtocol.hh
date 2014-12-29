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
protected:
    unsigned char* buffer;
	int bufferSize;
    unsigned int sec;
	unsigned int msec;

	void setTime();
public:
    AProtocol(unsigned char *buffer, int bufferSize);
    AProtocol();
    virtual ~AProtocol();
    unsigned char* getBuffer();
    void setBuffer(unsigned char* buffer);
    int getBufferSize() const;
    void setBufferSize(int bufferSize);
    void actualizeBuffer();
    virtual int getTotalHeaderSize() = 0;
    virtual int getTotalNbByteInBufferNeed() = 0;
	virtual void setDataOnBuffer() = 0;
    virtual std::string toString() = 0;
	virtual std::string getSource() = 0;
    virtual std::string getDestination() = 0;
	unsigned int getMsec() const;
	void setMsec(unsigned int msec);
	unsigned int getSec() const;
	void setSec(unsigned int sec);
};

template<typename T>
class ASubProtocol: public T {
	static_assert(std::is_base_of<AProtocol, T>::value, "Typename T must overload IProtocol");
public:
	virtual ~ASubProtocol() {
	}
	ASubProtocol() {

	}
    ASubProtocol(unsigned char *buffer, int bufferSize) :
			T(buffer, bufferSize) {

    }
    virtual int getTotalHeaderSize() = 0;
    virtual int getTotalNbByteInBufferNeed() = 0;
    virtual void setDataOnBuffer() = 0;
    virtual std::string toString() = 0;
    virtual std::string getSource() = 0;
    virtual std::string getDestination() = 0;
};


std::ostream& operator <<(std::ostream& stream, AProtocol& p);

#endif /* PACKET_APROTOCOL_HH_ */
