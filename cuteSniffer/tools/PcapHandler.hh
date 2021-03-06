/*
 * PcapReader.hh
 *
 *  Created on: 29 déc. 2014
 *      Author: cursan_a
 */

#ifndef CUTESNIFFER2_TOOLS_PCAPHANDLER_HH_
#define CUTESNIFFER2_TOOLS_PCAPHANDLER_HH_

#include "Ethernet.hh"
#include <string>
#include <list>
#include <iostream>
#include <fstream>

typedef unsigned int guint32 ;
typedef unsigned short guint16;
typedef int gint32;

class PcapHandler {
public :
	typedef struct pcap_hdr_s {
	        guint32 magic_number;   /* magic number */
	        guint16 version_major;  /* major version number */
	        guint16 version_minor;  /* minor version number */
	        gint32  thiszone;       /* GMT to local correction */
	        guint32 sigfigs;        /* accuracy of timestamps */
	        guint32 snaplen;        /* max length of captured packets, in octets */
	        guint32 network;        /* data link type */
	} pcap_hdr_t;

	typedef struct pcaprec_hdr_s {
	        guint32 ts_sec;         /* timestamp seconds */
	        guint32 ts_usec;        /* timestamp microseconds */
	        guint32 incl_len;       /* number of octets of packet saved in file */
	        guint32 orig_len;       /* actual length of packet */
	} pcaprec_hdr_t;

private:
	std::string path;
	std::ifstream rfile;
	std::ofstream wfile;
	pcap_hdr_t header;
	unsigned int lenFile;
	unsigned int cursor;

public:
    PcapHandler(std::string const &path);
	std::list<Ethernet *> getPackets();
	void writeFile(std::list<Ethernet *> packets);
private:
	void openReadFile();
	void openWriteFile();
	void getHeader();
	void setHeader();
};

#endif /* CUTESNIFFER2_TOOLS_PCAPHANDLER_HH_ */
