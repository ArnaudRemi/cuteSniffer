/*
 * ICMPV6.hh
 *
 *  Created on: 7 déc. 2014
 *      Author: cursan_a
 */

#ifndef PACKET_ICMPV6_HH_
#define PACKET_ICMPV6_HH_

template<class T>
class ICMPV6: public ASubProtocol<T> {
private:
	typedef struct s_icmpv6 {
	    unsigned char type;
	    unsigned char code;
	    unsigned short checksum;
	} icmpv6_header;
	icmpv6_header header;
public:
	ICMPV6() {
		memset(&this->header, 0, sizeof(icmpv6_header));
	}

    ICMPV6(unsigned char* data, int dataSize) :
			ASubProtocol<T>(data, dataSize) {
        if (dataSize >= this->getTotalHeaderSize())
            memcpy(&this->header, data + T::getTotalHeaderSize(),
					sizeof(icmpv6_header));
		else
			memset(&this->header, 0, sizeof(icmpv6_header));
	}

	ICMPV6(T &pqt) {
		new (this) ICMPV6(pqt.getBuffer(), pqt.getBufferSize());
	}

	virtual ~ICMPV6() {
    }

    virtual int getTotalHeaderSize() {
        return T::getTotalHeaderSize() + sizeof(icmpv6_header);
    }

    virtual int getTotalNbByteInBufferNeed() {
        return this->getTotalHeaderSize();
    }

	virtual void setDataOnBuffer() {
		T::setDataOnBuffer();
        memcpy(this->buffer + T::getTotalHeaderSize(), &(this->header),
				sizeof(icmpv6_header));
	}

	virtual std::string toString() {
		std::ostringstream stream;
        stream << T::toString() << "ICMPV6(" << this->getTotalHeaderSize()
				<< ")=[type : " << this->getType() << "]" << std::endl;
		return stream.str();
	}

	unsigned short getChecksum() const {
		return this->header.checksum;
	}

	void setChecksum(unsigned short checksum) {
		this->header.checksum = checksum;
	}

	unsigned char getCode() const {
		return this->header.code;
	}

	void setCode(unsigned char code) {
		this->header.code = code;
	}

	unsigned char getType() const {
		return this->header.type;
	}

	void setType(unsigned char type) {
		this->header.type = type;
	}
};


#endif /* PACKET_ICMPV6_HH_ */
