/*


int main()
{
    struct sockaddr_in source, destination = {};  //two sockets declared as previously
    int sock = 0;
    int datalen = 0;
    int pkt = 0;

    uint8_t *send_buffer, *recv_buffer;

    struct sockaddr_storage fromAddr;   // same as the previous entity struct sockaddr_storage serverStorage;
    unsigned int addrlen;  //in the previous example socklen_t addr_size;
    struct timeval tv;
    tv.tv_sec = 3;  /* 3 Seconds Time-out */
    //tv.tv_usec = 0;

    /* creating the socket */         
    //if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) 
    //    printf("Failed to create socket\n");

    /*set the socket options*/
    //setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(struct timeval));

    /*Inititalize source to zero*/
    //memset(&source, 0, sizeof(source));       //source is an instance of sockaddr_in. Initialization to zero
    /*Inititalize destinaton to zero*/
    //memset(&destination, 0, sizeof(destination));


    /*---- Configure settings of the source address struct, WHERE THE PACKET IS COMING FROM ----*/
    /* Address family = Internet */
    //source.sin_family = AF_INET;    
    /* Set IP address to localhost */   
    //source.sin_addr.s_addr = INADDR_ANY;  //INADDR_ANY = 0.0.0.0
    /* Set port number, using htons function to use proper byte order */
    //source.sin_port = htons(7005); 
    /* Set all bits of the padding field to 0 */
    //memset(source.sin_zero, '\0', sizeof source.sin_zero); //optional


    /*bind socket to the source WHERE THE PACKET IS COMING FROM*/
  //  if (bind(sock, (struct sockaddr *) &source, sizeof(source)) < 0) 
//        printf("Failed to bind socket");

    /* setting the destination, i.e our OWN IP ADDRESS AND PORT */
    /*destination.sin_family = AF_INET;                 
    destination.sin_addr.s_addr = inet_addr("127.0.0.1");  
    destination.sin_port = htons(7005); 

    //Creating a Buffer;
    send_buffer=(uint8_t *) malloc(350);
    recv_buffer=(uint8_t *) malloc(250);

    addrlen=sizeof(fromAddr);

    memset((void *) recv_buffer, 0, 250);
    memset((void *) send_buffer, 0, 350);

    sendto(sock, send_buffer, 20, 0,(struct sockaddr *) &destination, sizeof(destination));

    pkt=recvfrom(sock, recv_buffer, 98,0,(struct sockaddr *)&destination, &addrlen);
    if(pkt > 0)
        printf("%u bytes received\n", pkt);
    }
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

#include <arpa/inet.h>

#include "error.h"


#define BACKLOG 100

int main(int argc, char const *argv[])
{
	struct sockaddr_in sockin;

	pid_t sockId = socket(AF_INET, SOCK_DGRAM,0);

	if (sockId == -1){
		err("Error Socket open");
	}

	int portno = 3002;
	memset(&sockin, 0, sizeof(sockin));
	sockin.sin_family = AF_INET;
	sockin.sin_addr.s_addr = INADDR_ANY;
	sockin.sin_port = htons(portno);

	if (bind(sockId, (const struct sockaddr *) &sockin, sizeof(sockin)) < -1) {
		err("Error while binding address");
	}
	if (listen(sockId, BACKLOG) < 0) {
		err("listen error");
	}
	// accept not work of UDP only work for (SOCK_STREAM, SOCK_SEQPACKET)
	if (accept(sockId, NULL, NULL) < 0) {
		err("accept error");
	}


	return 0;
}