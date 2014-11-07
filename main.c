#include <stdio.h> //For standard things
#include <stdlib.h>    //malloc
#include <string.h>    //memset
#include <netinet/ip_icmp.h>   //Provides declarations for icmp header
#include <netinet/udp.h>   //Provides declarations for udp header
#include <netinet/tcp.h>   //Provides declarations for tcp header
#include <netinet/ip.h>    //Provides declarations for ip header
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/ethernet.h>  //For ether_header

int processPacket(char * buffer , int data_size){
    int j;

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
        printf("IP\n");
    if (*(buffer+12)==8 && *(buffer+13)==6)
        printf("ARP\n");

    printf("\nEnd of paquet\n");
    return 0;
}

int main()
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
    //sock_raw = socket(AF_INET , SOCK_RAW , IPPROTO_RAW);
    //sock_raw = socket(AF_INET ,SOCK_RAW , IPPROTO_ICMP);

    //sock_raw = socket(AF_NETLINK, SOCK_RAW, NETLINK_NETFILTER);
    //sock_raw = socket(AF_NIT, SOCK_RAW, NITPROTO_RAW);
    //fd = socket(PF_RAW, SOCK_RAW, RAWPROTO_SNOOP);
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
        else if(data_size > 0)
            printf("OK!\n");
        //Now process the packet
        processPacket(buffer , data_size);
    }
}

