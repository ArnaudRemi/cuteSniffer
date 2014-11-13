#include <stdio.h> //For standard things
#include <stdlib.h>    //malloc
#include <string.h>    //memset
#include <netinet/ip_icmp.h>   //Provides declarations for icmp header
#include <netinet/udp.h>   //Provides declarations for udp header
#include <netinet/tcp.h>   //Provides declarations for tcp header
#include <netinet/ip.h>    //Provides declarations for ip header
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <net/ethernet.h>  //For ether_header
#include <net/if.h>
#include <netpacket/packet.h>

#include "cuteSniffer.h"

int defineProtocol(char * buffer , int data_size){
    int j;
    type_proto p = OTHER;

    printf("Ethernet Header\n");

    printf("destination address: ");
    for (j=0;j<6;j++) 
        printf("%02x:",*(buffer+j));
    printf(" source address: ");
    for (j=6;j<12;j++) 
        printf("%02x:",*(buffer+j));
    printf(" Ether protocol number: \n");
    for (j=12;j<14;j++) 
        printf("%02x:",*(buffer+j));
    if (*(buffer+12)==8 && *(buffer+13)==0)
        p = IPV4;
    if (*(buffer+12)==134 && *(buffer+13)==221)
        p = IPV6;
    if (*(buffer+12)==8 && *(buffer+13)==6)
        p = ARP;

    //if IPVx -> is ICMP_Vx

    printf("\n");
    switch(p){
        case IPV4:
            printf("IPV4\n");
            break;
        case IPV6:
            printf("IPV6\n");
            break;
        case ARP:
            printf("ARP\n");
            break;
        default:
            printf("UNKNOWN\n");
    }

    printf("\nEnd of paquet\n");
    return p;
}

int go_promiscuous(int sock, const char *device)
{
  struct ifreq ifr;
  struct packet_mreq mr;
  struct sockaddr_ll sll;
  ifr.ifr_ifindex = 0;
  strcpy(ifr.ifr_name, device);
  if(ioctl(sock,SIOGIFINDEX,&ifr) < 0)
  {
    perror("ioctl error ");
    return 1;
  }

  memset(&mr,0,sizeof(mr));
  mr.mr_ifindex = ifr.ifr_ifindex;
  mr.mr_type =  PACKET_MR_PROMISC;
  if(setsockopt(sock, SOL_PACKET, PACKET_ADD_MEMBERSHIP, (char *)&mr, sizeof(mr)) < 0) {
    perror("setsockopt error ");
    return 1;
  }
  return 0;
}

int main(int ac, char **av)
{
    int saddr_size , data_size;
    struct sockaddr saddr;
    struct in_addr in;
    int sock_raw;

    

    unsigned char *buffer = (unsigned char *)malloc(65536); //Its Big!
     
//    logfile=fopen("log.txt","w");
//    if(logfile==NULL) printf("Unable to create file.");
    printf("Starting...\n");
    //Create a raw socket that shall sniff
    sock_raw = socket(PF_PACKET , SOCK_RAW , htons(ETH_P_ALL));

    go_promiscuous(sock_raw, "wlan3");

    if(sock_raw < 0)
    {
        printf("Socket Error\n");
        return 1;
    }
    while(1)
    {
        saddr_size = sizeof saddr;
        //Receive a packet
        //data_size = recvfrom(sock_raw , buffer , 65536 , 0 , &saddr , &saddr_size);
        data_size = read(sock_raw, buffer, 65535); 
        if(data_size < 0)
        {
            printf("Recvfrom error , failed to get packets\n");
            return 1;
        }
/*        else if(data_size > 0)
            printf("OK!\n");*/
        //Now process the packet
        defineProtocol(buffer , data_size);
    }
}

