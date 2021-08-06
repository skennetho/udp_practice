#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "DronePacket.h"


using namespace std;

//참고: https://stackoverflow.com/questions/3784263/converting-an-int-into-a-4-byte-char-array-c


void test_serializer_logic_test(){
    //serialize///////////////////////////////////////////
    double latitude = 12.123456;
    int state = 234;
    char *name = "Awe-some";
    vector<int> empty = {2,4,6,8};

    char data[100];   //space for serialized data
    int loc =0;

    char* byte_lat = reinterpret_cast<char*>(&latitude);
    for(int i =0 ; i< 8; i++){
        data[loc++] = byte_lat[i];
    } 

    char* byte_sta = reinterpret_cast< char*>(&state);
    for(int i =0 ; i< 4; i++){
        data[loc++] = byte_sta[i];
    } 

    for(int i=0; i<8 ; i++){
        data[loc++] = name[i];
    }

    for(int i=0; i< empty.size(); i++){
        char* byte = reinterpret_cast<  char*>(&empty.at(i));
        for(int j =0 ; j< 4; j++){
            data[loc++] = byte[j];
        } 
    }
    cout<<latitude<<endl;
    cout<<state<<endl;
    cout<<name<<endl;
    cout<<"empty = [ ";
    for_each(empty.begin(), empty.end(), [&](int& n){
        cout << n << " ";        //output  참조:https://hwan-shell.tistory.com/119
    });
    cout<<"]"<<endl;


    //deserialize///////////////////////////////////////
    char double_buff[8];
    char int_buff[4];
    int receive_loc =0;

    for(int i=0; i <8; i++){
        double_buff[i] = data[receive_loc++];
    }
    latitude = *reinterpret_cast<double*>(double_buff);
    cout<<latitude<<endl;


    for(int i=0; i <4; i++){
        int_buff[i] = data[receive_loc++];
    }
    state = *reinterpret_cast<int*>(int_buff);
    cout<<state<<endl;

    string rec_name ="";
    for(int i=0; i <8; i++){
        rec_name+= data[receive_loc++];
        // cout<<strlen(rec_name)<<endl;
    }

    cout<<rec_name<<' '<<endl;

    vector<int> receive;
    int empty_size = (loc - receive_loc)/4;
    for(int i =0;i<empty_size;i++){
        for(int j=0; j<4;j++){
            int_buff[j]= data[receive_loc++];
        }
        int num = *reinterpret_cast<int*>(int_buff);
        receive.push_back(*reinterpret_cast<int*>(int_buff));
    }

    cout<<"empty = [ ";
    for_each(receive.begin(), receive.end(), [&](int& n){
        cout << n << " ";        //output  참조:https://hwan-shell.tistory.com/119
    });
    cout<<']'<<endl;
    cout<<loc<<' '<<receive_loc<<endl;
}
void test_serialization_array(){
    //  //serialize
    // double latitude = 12.123456;
    // int state = 234;
    // char *name = "Awe-some";
    // vector<int> empty = {2,4,6,8};

    // char data[4];   //space for serialized data
    // char data2[4];
    // int loc =0;

    // char* byte_sta = reinterpret_cast< char*>(&state);              //serialize
    // for(int i =0 ; i< 4; i++){
    //     data[loc++] = byte_sta[i];
    // } 

    // loc =0;
    // serializeInteger(data2, state, loc);                            //serialize func
    // for(int i =0 ; i<4;i++){
    //     cout<<(int)data[i] << "=="<<(int)data2[i]<<endl;
    // }

    // int num ;
    // // num= *reinterpret_cast<int*>(data);
    // // cout<<"serialized! data = "<<num<<endl;
    
    // cout<<"serializing data... "<<endl;
    // deserializeInteger(data, num, loc);
    // cout<<"serialized! data= "<<num<<endl;

   

    // cout<<"serializing _data... "<<endl;
    // deserializeInteger(_data, num, loc);
    // cout<<"serialized! _data= "<<num<<endl;

    // for(int i =0 ; i<4;i++){
    //     cout<<(int)data[i] << "=="<<(int)data2[i]<<endl;
    // }
}

void test()
{
    DronePacket drone;
    
    vector<int> arr = {10};
    drone.setEmpty(arr);
    drone.setCompanyID("AWE-SOME");
    drone.setDroneID("DRONE001");
    drone.setLatitudeLongitudeAltitude(37.466142,126.434131,123.4);
    drone.setStateMissionTypeMissionDetail(0,1,2);
    drone.setTimeStamp("12.34.56.789");
    drone.calcSize();
    //drone.printData();

    int length = drone.getSize();
    cout<<"drone packet's length ="<<length<< endl;

    char data[length];
    drone.serialize(data);


    cout<<":::drone2 printing..."<<endl;
    DronePacket drone2;
    drone2.deserialize(data);
    drone2.printData();

   
}

void makeArray(char data[]){
    char arr[4] = {'w','h','a','t'};
    data = arr;
}
void printArray(char data[]){
    cout<<"data in printArray()= [ ";
    for(int i =0 ;i<4;i++){
        cout<<(int)data[i]<<" ";
    }
    cout<<']'<<endl;
}
void test_function_pointerArray()
{
    char* data;
    makeArray(data);
    cout<<"data in test()= [ ";
    for(int i =0 ;i<4;i++){
        cout<<(int)data[i]<<" ";
    }
    cout<<']'<<endl;
    printArray(data);
}

int main(void)
{
    test();
    return 0;
}