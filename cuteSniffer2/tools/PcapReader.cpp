/*
 * PcapReader.cpp
 *
 *  Created on: 29 déc. 2014
 *      Author: cursan_a
 */

#include "PcapReader.hh"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdexcept>


PcapReader::PcapReader(std::string path) : path(path), lenFile(0), cursor(0){

}

std::list<Ethernet *> PcapReader::getPackets() {
	this->openFile();
	this->getHeader();
	PcapReader::pcaprec_hdr_t headerPqt;
	std::list<Ethernet *> ret;

	while (cursor < lenFile) {
		if (cursor + sizeof(PcapReader::pcaprec_hdr_t) > lenFile)
			throw std::invalid_argument("Le fichier est tronqué");
		file.read((char *)&(headerPqt), sizeof(PcapReader::pcaprec_hdr_t));
		if (!file) {
			file.close();
			throw std::runtime_error("Erreur dans la lecture du fichier");
		}
		cursor += sizeof(PcapReader::pcaprec_hdr_t);
		if (!headerPqt.incl_len)
			continue;
		std::cout << "len : " << headerPqt.incl_len << "/" << headerPqt.orig_len << std::endl;
		unsigned char *buffer = new unsigned char[headerPqt.incl_len];
		if (!buffer) {
			file.close();
			throw std::bad_alloc();
		}
		file.read((char *)buffer, headerPqt.incl_len);
		if (!file) {
			file.close();
			throw std::runtime_error("Erreur dans la lecture du fichier");
		}
		ret.push_back(new Ethernet(buffer, headerPqt.incl_len));
		cursor += headerPqt.incl_len;
	}
	return (ret);
}

void PcapReader::openFile() {
	file.open(path, std::ios::binary | std::ios::ate);
	if (!file.is_open())
		throw std::invalid_argument("Impossible d'ouvrir le fichier pcap");
	lenFile = file.tellg();
	file.seekg (0,file.beg);
}

void PcapReader::getHeader() {
	if (lenFile < sizeof(PcapReader::pcap_hdr_t)) {
		file.close();
		throw std::invalid_argument("Le fichier n'est pas dans un format valide (bad lenght)");
	}
	file.read((char *)&(this->header), sizeof(PcapReader::pcap_hdr_t));
	if (!file) {
		file.close();
		throw std::runtime_error("Erreur dans la lecture du fichier");
	}
	cursor += sizeof(PcapReader::pcap_hdr_t);
	if (this->header.magic_number != 0xa1b2c3d4) {
		file.close();
		throw std::invalid_argument("Le fichier n'est pas dans un format valide (bad magic_number)");
	}
}
