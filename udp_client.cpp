#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "DronePacket.h"
#include "converter.h"
#include "unistd.h"
 
#define PORT 3333

int main(void){
    int sock;
    struct sockaddr_in target_addr;
    char recv_buffer[1024];
    int recv_len;
    int addr_len;

    // /*DronePacket Data test ////////////////////////////////////
    DronePacket drone;
    vector<int> arr = {10,20,30};
    drone.setEmpty(arr);
    drone.setCompanyID("AWE-SOME");
    drone.setDroneID("drone123");
    drone.setLatitudeLongitudeAltitude(37.466142,126.434131,123.4);
    drone.setStateMissionTypeMissionDetail(0,1,2);
    drone.setTimeStamp("12.34.56.789");
    drone.calcSize();

    char data[drone.getSize()];
    drone.serialize(data);
    // drone.printData();
    // cout<<"data= [ ";
    // for(int i =0 ;i<drone.getSize();i++){
    //     cout<<"'"<<(int)data[i]<<"', ";
    // }
    // cout<<']'<<endl;
    DronePacket drone2;
    drone2.deserialize(data);
    // drone2.printData();

    cout<<"ready..."<<endl; 
    //////////////////////////////////////////////////////////*/

    if((sock = socket(AF_INET , SOCK_DGRAM, 0))<0){
        perror("socket");
        return 1;
    }
    cout<<"socket..."<<endl; 


    memset(&target_addr, 0x00, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr("192.168.0.40");                   //IP
    target_addr.sin_port = htons(PORT);                                     //PORT

    addr_len = sizeof(target_addr);
    //////////////////////////////////////////////1초마다 
    for(int i =0 ; i< 30; i++){
        sendto(sock, data, drone.getSize(), 0 , (struct sockaddr*)&target_addr, addr_len);
        cout<<"sending drone packet..."<<endl; 

        sleep(1);
    }

    sendto(sock, data, drone.getSize(), 0 , (struct sockaddr*)&target_addr, addr_len);                                   

    if((recv_len = recvfrom(sock, recv_buffer, 1024, 0, (struct sockaddr *)&target_addr,  (socklen_t*)&addr_len)) < 0){
        perror("recvfrom ");
        return 1;
    }

    recv_buffer[recv_len] = '\0';

    printf("ip : %s \n", inet_ntoa(target_addr.sin_addr));

    // cout<<"recv_buffer= [ ";
    // for(int i =0 ;i<recv_len;i++){
    //     cout<<"'"<<(int)recv_buffer[i]<<"', ";
    // }
    // cout<<']'<<endl;

    close(sock);

    return 0;
}