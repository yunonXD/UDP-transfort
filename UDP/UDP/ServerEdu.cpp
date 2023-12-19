#include <stdio.h>
#include <winsock2.h>

int main(int argc, char** argv[]) {

	int sockfd = 0;
	int socket(int domain, int type, int protocol);
	//1. 소켓의 생성
	//소켓 함수의 원형
	//endpoint 소켓 생성 *종점소켓
	// 도메인 값 / 타입 값 / 트포토콜

	if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {

	}

	//2. bind 함수로 소켓을 설정
	int bind(int sockfd, struct sockaddr* my_addr, socklen_t, addrlen);
	//sockfd			: 앞에 생성되어진 endpoint 소켓
	//my_addr			: ip 및 port 번호 저장용 변수가 있는 struct
	//addrlen			: 두번째 인자 전달 크기
	//리턴값				: 성공0 실패 -1 리턴
	struct sockaddr_in clientaddr, serveraddr, myaddr;

	memset(&serveraddr, 0x00, sizeof(serveraddr));				//두번째 인자 구조체를 이용해서 주소와 포트번호를 저장함
	serveraddr.sin_family = AF_INET;							//주소 체계를 저장
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);				//연결할 인터넷 주소를 지정함 INADDR_ANY는 기다리기만 하고 연결 대상은 없기 때문
	serveraddr.sin_port = htons(12345);							//서버는 기다릴 포트 번호 클라는 연결할 포트번호
	int state = bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
	if (state == -1) {
		perror("bind error :");
		exit(0);
	}


	//3. listen 함수로 수신 대기열 설정
	int listen(int sockfd, int backlog);
	//sockfd			: 앞에 생성되어진 endpoint 소켓
	//blacklog			: 수신 대기열의 크기. 실행결과 성공0 실패-1



	
	//4. accept 함수로 연결 대기
	int accept(int sockfd, struct sockaddr* addr, socklen_t * addrlen);
	//sockfd			: 앞에 생성되어진 클라이언트 요청 받으들이는 소켓
	//addr				: accept 함수 성공시 클라 주소와 포트를 해당 구조체에게 전달 (클라 정보 확인,저장 용도로 사용 가능)
	//addrlen			: sockaddr 구조체 크기
	//함수 성공시 0보다 큰 값 리턴
	struct sockaddr_in client_sockaddr;
	int client_sockfd;
	int client_addr_size;

	while (1) {
		client_addr_size = sizeof(client_addr);
		client_sockfd = accept(sockfd, (struct sockaddr*)&client_sockaddr), &client_addr_size);
	}

	if (client_socket == -1) {
		//에러처리
	}
	else {
		//client_socket을 이용한 서버통신 (전달받은 주소,포트를 바탕으로)
	}




	//5. connect 연결 요청하기
	int connect(int sockfd, const struct sockaddr* serv_addr, socklen_t addrlen);
	//sockfd			: sock 함수로 만들어진 소켓 지정 번호
	//serv_addr			: 연결할 서버의 ip 주소 포트 등의 정보를 알려주는 용도
	//addren			: server_addr 크기
	//반환				: 연결 성공 0 실패시 -1 (성공 실패만 리턴)
	
	int server_sockfd = 0;
	if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("error :");
		exit(0);
	}

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");		// <<inet_addr 127주소를 2진 주소로 변환
	serveraddr.sin_port = htons(3000);

	int client_len = sizeof(serveraddr);

	if (connect(server_sockfd, (struct sockaddr*)&serveraddr, client_len) == -1) {
		perror("exit : ");
		exit(0);
	}



	//6. Read / Write 데이터 읽기 쓰기
	SSIZE_T read(int fd, void* buf, size_t count);
	//fd			: 열린 파일의 지정번호 -소켓 지정번호
	//buf			: 읽어드인 데이터가 저장될 버퍼변수
	//count			: 읽어들일 데이터의 count 크기
	//리턴값			: 성공하면 읽은 데이터의 byte-단위를 출력 실패시 -1

	int readn;
	char buf[80];
	memset(buf ,0x00 ,80);
	readn = read(sockfd, buf, 80);
	//sockfd소켓 n번에서 에서 가져온 파일을 buf[80]에 저장하고 카운트 크기를 저장


	size_t write(int fd, const void* buf, size_t count);
	//fd			: 연결된 소켓 지정 번호
	//buf			: 보낼 데이터가 저장되어 있는 버퍼
	//count			: 보낼 데이터의 크기
	//리턴값			: 성공시 데이터의 크기를, 실패시 -1 출력

	int fd = 100;
	struct user_info {
		int age;
		char name[30];
	};
	//...
	struct user_info mydata;
	mydata.age = htonl(25);
	strncpy(mydata.name, "RealName\0" , sizeof(mydata.name));		//되도록이면 strcpy는 쓰지말것 오버플로우 공격시 취약함
	int writen = write(fd, (void*)&mydata, sizeof(mydata));			//만약 strcpy를 꼭 써야한다면 파일 끝에 엔드포인트 \0 << 명시 필요


	//7. close소켓 종료
	int close(int sockfd);

	return 0;
}