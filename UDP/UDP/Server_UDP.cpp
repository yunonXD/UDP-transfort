#include<winsock2.h>
#include<stdio.h>
#include<string.h>
#include <io.h>

#define MAXBUF 1024

int main(int argc, char** argv) {

	int server_sockfd, client_sockfd;
	int client_len ,n;
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
	memset(&serveraddr ,0x00 ,sizeof(serveraddr));
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

	//do whileing process client thing
	//	4.5.6. accept and read & write
	while (1) {
		memset(buf, 0x00, MAXBUF);
		client_sockfd = accept(server_sockfd, (struct sockaddr*)&clientaddr, &client_len);

		printf("newer client connect : %s\n" , inet_ntoa(clientaddr.sin_addr));

		if ((n = _read(client_sockfd, buf, MAXBUF) <= 0)) {
			_close(client_sockfd);
			continue;
		}
		if (_write(client_sockfd, buf, MAXBUF) <= 0) {
			perror("Write error : ");
			_close(client_sockfd);
		}
		_close(client_sockfd);
	}

	//	7.close
	_close(server_sockfd);
	return 0;

}

