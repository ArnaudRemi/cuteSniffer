#include <stdio.h> //For standard things
#include <stdlib.h>    //malloc
#include <string.h>    //memset
#include <netinet/ip_icmp.h>   //Provides declarations for icmp header
#include <netinet/udp.h>   //Provides declarations for udp header
#include <netinet/tcp.h>   //Provides declarations for tcp header
#include <netinet/ip.h>    //Provides declarations for ip header
#include <netinet/in.h>
#include <sys/types.h>

#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <net/ethernet.h>  //For ether_header
#include <net/if.h>
#include <netpacket/packet.h>

#include "RawSocket.h"

int main(int ac, char **av){

    RawSocket *rs = new RawSocket;

    rs->goPromiscious("wlan0");

    rs->readNext();

    rs->getPacket();

}

/*int main(int ac, char **av)
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
/ *        else if(data_size > 0)
            printf("OK!\n");* /
        //Now process the packet
        defineProtocol(buffer , data_size);
    }
}*/

