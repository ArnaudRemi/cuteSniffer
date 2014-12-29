/*
 * PcapReader.cpp
 *
 *  Created on: 29 déc. 2014
 *      Author: cursan_a
 */

#include "PcapHandler.hh"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdexcept>


PcapHandler::PcapHandler(std::string const &path) : path(path), lenFile(0), cursor(0){

}

std::list<Ethernet *> PcapHandler::getPackets() {
	this->openReadFile();
	this->getHeader();
	PcapHandler::pcaprec_hdr_t headerPqt;
	std::list<Ethernet *> ret;

	while (cursor < lenFile) {
		if (cursor + sizeof(PcapHandler::pcaprec_hdr_t) > lenFile)
			throw std::invalid_argument("Le fichier est tronqué");
		rfile.read((char *)&(headerPqt), sizeof(PcapHandler::pcaprec_hdr_t));
		if (!rfile) {
			rfile.close();
			throw std::runtime_error("Erreur dans la lecture du fichier");
		}
		cursor += sizeof(PcapHandler::pcaprec_hdr_t);
		if (!headerPqt.incl_len)
            continue;
		unsigned char *buffer = new unsigned char[headerPqt.incl_len];
		if (!buffer) {
			rfile.close();
			throw std::bad_alloc();
		}
		rfile.read((char *)buffer, headerPqt.incl_len);
		if (!rfile) {
			rfile.close();
			throw std::runtime_error("Erreur dans la lecture du fichier");
		}
		ret.push_back(new Ethernet(buffer, headerPqt.incl_len));
		cursor += headerPqt.incl_len;
	}
	rfile.close();
	return (ret);
}

void PcapHandler::writeFile(std::list<Ethernet *> packets) {
	PcapHandler::pcaprec_hdr_t headerPacket;
	this->openWriteFile();
	this->setHeader();
	for (Ethernet *packet : packets) {
		headerPacket.ts_sec = packet->getSec();
		headerPacket.ts_usec = packet->getMsec();
		headerPacket.incl_len = (packet->getBufferSize() > 65535) ? 65535 : packet->getBufferSize();
		headerPacket.orig_len = packet->getBufferSize();
		wfile.write((char *)&headerPacket, sizeof(PcapHandler::pcaprec_hdr_t));
		if (!wfile) {
			wfile.close();
			throw std::runtime_error("Impossible d'écrire dans le fichier");
		}
		wfile.write((char *)packet->getBuffer(), headerPacket.incl_len);
		if (!wfile) {
			wfile.close();
			throw std::runtime_error("Impossible d'écrire dans le fichier");
		}
	}
	wfile.close();
}

void PcapHandler::openReadFile() {
	rfile.open(path, std::ios::binary | std::ios::ate);
	if (!rfile.is_open())
		throw std::invalid_argument("Impossible d'ouvrir le fichier pcap");
	lenFile = rfile.tellg();
    rfile.seekg (0, rfile.beg);
}

void PcapHandler::openWriteFile() {
	wfile.open(path, std::ios::binary);
	if (!wfile.is_open())
		throw std::invalid_argument("Impossible d'ouvrir le fichier pcap");
	lenFile = 0;
}

void PcapHandler::getHeader() {
	if (lenFile < sizeof(PcapHandler::pcap_hdr_t)) {
		rfile.close();
		throw std::invalid_argument("Le fichier n'est pas dans un format valide (bad lenght)");
	}
	rfile.read((char *)&(this->header), sizeof(PcapHandler::pcap_hdr_t));
	if (!rfile) {
		rfile.close();
		throw std::runtime_error("Erreur dans la lecture du fichier");
	}
	cursor += sizeof(PcapHandler::pcap_hdr_t);
	if (this->header.magic_number != 0xa1b2c3d4) {
		rfile.close();
		throw std::invalid_argument("Le fichier n'est pas dans un format valide (bad magic_number)");
    }
    std::cout << "magic number : "  << this->header.magic_number << std::endl;
    std::cout << "version major : "  << this->header.version_major << std::endl;
    std::cout << "version minor : "  << this->header.version_minor << std::endl;
    std::cout << "thiszone : "  << this->header.thiszone << std::endl;
    std::cout << "sigfigs : "  << this->header.sigfigs << std::endl;
    std::cout << "snaplen : "  << this->header.snaplen << std::endl;
    std::cout << "network : "  << this->header.network << std::endl << std::endl;
}

void PcapHandler::setHeader() {
	this->header.magic_number = 0xa1b2c3d4;
	this->header.version_major = 2;
	this->header.version_minor = 4;
	this->header.thiszone = 0;
	this->header.sigfigs = 0;
	this->header.snaplen = 65535;
	this->header.network = 1;
	wfile.write((char *)&(this->header), sizeof(PcapHandler::pcap_hdr_t));
	if (!wfile) {
		wfile.close();
		throw std::runtime_error("Impossible d'écrire dans le fichier");
	}
}
