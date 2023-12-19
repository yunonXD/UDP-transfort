#include <winsock2.h>
#include<iostream>
#include<string.h>

#define MAXBUF 1024
using namespace std;

int main(int arvc, char** argv) {

	int server_sockfd=0, client_slockfd=0;
	int client_len =0 ,n=0;
	char buf[MAXBUF];
	struct sockaddr_in clientaddr ,serveraddr;	//bind

	client_len = sizeof(clientaddr);

	//	1.made new UDP socket (socket)
	if ((server_sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
		perror("UDP Sock made failed. pls check addr or ip setting.");
		exit(0);
	}

	////bind=========================================
	//this part made ip addr and port, protocol.
	memset(&serveraddr,0 ,sizeof(serveraddr));
	//host byte order
	serveraddr.sin_family = AF_INET;					
	//network byte order
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);		//0,0,0,0	 host to network long		record byte first
	serveraddr.sin_port = htons(atoi(argv[1]));			//record byte first. sin_addr and sin_port need to capsul

	//	2. bind set socket
	bind(server_sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

	//===============================================

	//	3.listen calling the client
	listen(server_sockfd, 5);

}

