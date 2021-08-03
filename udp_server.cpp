#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <fcntl.h>
#include <sys/file.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
# include <netinet/in.h>    //IPv4 전용 기능을 사용할 경우
# include <sys/socket.h>    //주소변환 기능을 사용할 경우
# include <arpa/inet.h>     //Name Resolution을 사용할 경우

#define PORT 9999

// 1. 소켓을 초기화 (socket)
    
// 2. 소켓에 IP 주소 및 포트 번호 부여 (bind)

// 3. 클라이언트의 데이터를 수신(recvfrom)

// 4. 클라이언트에게 수신된 데이터를 전송(sendto)

// 5. 소켓 연결 종료(close)
int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in addr, client_addr;
    char recv_buffer[1024];
    int recv_len;
    int addr_len;

    if((sock = socket(AF_INET, SOCK_DGRAM, 0)) <0){
        perror("socket");
        return 1;
    }

    memset(&addr, 0x00, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(PORT);

    if(bind(sock, (struct sockaddr *)&addr, sizeof(addr))<0){
        perror("bind");
        return 1;
    }

    printf("waiting for messages \n");

    addr_len = sizeof(client_addr);
    if((recv_len = recvfrom(sock, recv_buffer, 1024, 0 , (struct sockaddr *) &client_addr, (socklen_t*)&addr_len))<0){
        perror("recvfrom");
        return 1;
    }

    recv_buffer[recv_len] = '\0';

    printf("ip: %s\n", inet_ntoa(client_addr.sin_addr));
    printf("received data : %s\n", recv_buffer);

    sendto(sock, recv_buffer, strlen(recv_buffer), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));

    close(sock);

    return 0;
}