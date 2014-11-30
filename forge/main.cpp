#include <arpa/inet.h>
#include <linux/if_packet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/ether.h>
#include "Utils.hh"
 
int 					main(int argc, char *argv[])
{
	int 				sockfd;
	struct ifreq 		if_idx;
	struct ifreq 		if_mac;
	int 				tx_len = 0;
	char 				sendbuf[1024];
	struct ether_header *eh = (struct ether_header *)sendbuf;
	struct sockaddr_ll 	socket_address;
	std::string 		interface = "eth0";
	std::string			macSrc = "00:0c:29:a2:74:01";
	std::string			macDst = "00:11:22:33:44:55";
	
	if ((sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) == -1) {
	    perror("socket");
	}

	memset(&if_idx, 0, sizeof(struct ifreq));
	strncpy(if_idx.ifr_name, interface.c_str(), interface.size());
	if (ioctl(sockfd, SIOCGIFINDEX, &if_idx) < 0)
	    perror("SIOCGIFINDEX");

	memset(sendbuf, 0, 1024);

	unsigned char *macSrcByte = Utils::convertMacToByte(macSrc);
	unsigned char *macDstByte = Utils::convertMacToByte(macDst);
	memcpy(eh->ether_shost, macSrcByte, 6);
	memcpy(eh->ether_dhost, macDstByte, 6);

	eh->ether_type = htons(ETH_P_IP);
	tx_len += sizeof(struct ether_header);

	memcpy(sendbuf + tx_len, "Hello World !", strlen("Hello World !"));
	tx_len += strlen("Hello World !");

	memset(&socket_address, 0, sizeof(socket_address));
	socket_address.sll_ifindex = if_idx.ifr_ifindex;
	socket_address.sll_halen = ETH_ALEN;
	memcpy(socket_address.sll_addr, macDstByte, 6);

	if (sendto(sockfd, sendbuf, tx_len, 0, (struct sockaddr*)&socket_address, sizeof(struct sockaddr_ll)) < 0)
	    perror("Send failed");
 
	return (0);
}