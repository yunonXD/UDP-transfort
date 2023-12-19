#include <stdio.h>
#include <winsock2.h>

int main(int argc, char** argv[]) {

	int sockfd = 0;
	int socket(int domain, int type, int protocol);
	//1. ������ ����
	//���� �Լ��� ����
	//endpoint ���� ���� *��������
	// ������ �� / Ÿ�� �� / Ʈ������

	if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {

	}

	//2. bind �Լ��� ������ ����
	int bind(int sockfd, struct sockaddr* my_addr, socklen_t, addrlen);
	//sockfd			: �տ� �����Ǿ��� endpoint ����
	//my_addr			: ip �� port ��ȣ ����� ������ �ִ� struct
	//addrlen			: �ι�° ���� ���� ũ��
	//���ϰ�				: ����0 ���� -1 ����
	struct sockaddr_in clientaddr, serveraddr, myaddr;

	memset(&serveraddr, 0x00, sizeof(serveraddr));				//�ι�° ���� ����ü�� �̿��ؼ� �ּҿ� ��Ʈ��ȣ�� ������
	serveraddr.sin_family = AF_INET;							//�ּ� ü�踦 ����
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);				//������ ���ͳ� �ּҸ� ������ INADDR_ANY�� ��ٸ��⸸ �ϰ� ���� ����� ���� ����
	serveraddr.sin_port = htons(12345);							//������ ��ٸ� ��Ʈ ��ȣ Ŭ��� ������ ��Ʈ��ȣ
	int state = bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
	if (state == -1) {
		perror("bind error :");
		exit(0);
	}


	//3. listen �Լ��� ���� ��⿭ ����
	int listen(int sockfd, int backlog);
	//sockfd			: �տ� �����Ǿ��� endpoint ����
	//blacklog			: ���� ��⿭�� ũ��. ������ ����0 ����-1



	
	//4. accept �Լ��� ���� ���
	int accept(int sockfd, struct sockaddr* addr, socklen_t * addrlen);
	//sockfd			: �տ� �����Ǿ��� Ŭ���̾�Ʈ ��û �������̴� ����
	//addr				: accept �Լ� ������ Ŭ�� �ּҿ� ��Ʈ�� �ش� ����ü���� ���� (Ŭ�� ���� Ȯ��,���� �뵵�� ��� ����)
	//addrlen			: sockaddr ����ü ũ��
	//�Լ� ������ 0���� ū �� ����
	struct sockaddr_in client_sockaddr;
	int client_sockfd;
	int client_addr_size;

	while (1) {
		client_addr_size = sizeof(client_addr);
		client_sockfd = accept(sockfd, (struct sockaddr*)&client_sockaddr), &client_addr_size);
	}

	if (client_socket == -1) {
		//����ó��
	}
	else {
		//client_socket�� �̿��� ������� (���޹��� �ּ�,��Ʈ�� ��������)
	}




	//5. connect ���� ��û�ϱ�
	int connect(int sockfd, const struct sockaddr* serv_addr, socklen_t addrlen);
	//sockfd			: sock �Լ��� ������� ���� ���� ��ȣ
	//serv_addr			: ������ ������ ip �ּ� ��Ʈ ���� ������ �˷��ִ� �뵵
	//addren			: server_addr ũ��
	//��ȯ				: ���� ���� 0 ���н� -1 (���� ���и� ����)
	
	int server_sockfd = 0;
	if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("error :");
		exit(0);
	}

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");		// <<inet_addr 127�ּҸ� 2�� �ּҷ� ��ȯ
	serveraddr.sin_port = htons(3000);

	int client_len = sizeof(serveraddr);

	if (connect(server_sockfd, (struct sockaddr*)&serveraddr, client_len) == -1) {
		perror("exit : ");
		exit(0);
	}



	//6. Read / Write ������ �б� ����
	SSIZE_T read(int fd, void* buf, size_t count);
	//fd			: ���� ������ ������ȣ -���� ������ȣ
	//buf			: �о���� �����Ͱ� ����� ���ۺ���
	//count			: �о���� �������� count ũ��
	//���ϰ�			: �����ϸ� ���� �������� byte-������ ��� ���н� -1

	int readn;
	char buf[80];
	memset(buf ,0x00 ,80);
	readn = read(sockfd, buf, 80);
	//sockfd���� n������ ���� ������ ������ buf[80]�� �����ϰ� ī��Ʈ ũ�⸦ ����


	size_t write(int fd, const void* buf, size_t count);
	//fd			: ����� ���� ���� ��ȣ
	//buf			: ���� �����Ͱ� ����Ǿ� �ִ� ����
	//count			: ���� �������� ũ��
	//���ϰ�			: ������ �������� ũ�⸦, ���н� -1 ���

	int fd = 100;
	struct user_info {
		int age;
		char name[30];
	};
	//...
	struct user_info mydata;
	mydata.age = htonl(25);
	strncpy(mydata.name, "RealName\0" , sizeof(mydata.name));		//�ǵ����̸� strcpy�� �������� �����÷ο� ���ݽ� �����
	int writen = write(fd, (void*)&mydata, sizeof(mydata));			//���� strcpy�� �� ����Ѵٸ� ���� ���� ��������Ʈ \0 << ��� �ʿ�


	//7. close���� ����
	int close(int sockfd);

	return 0;
}