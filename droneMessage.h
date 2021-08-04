
#include<iostream>
#include<string>
using namespace std;

class DronePacket{
private:
    int length;         //76byte ~ 128byte
    char company_id[8]; //8byte       
    char drone_id[8];   //8byte
    double latitude;    //8byte
    double longitude;   //8byte
    double altitude;    //8byte
    char timeStamp[12]; //12byte
    int state;          //4byte
    int mission_type;   //4byte
    int mission_detail; //4byte
    int empty[52];      

    char* encodeToChar(int num){
        char* encoded;
        return encoded;
    }
    char* encodeToChar(double num){
        char* encoded;
        return encoded;
    }
    int decodeToInt(char* arr){
        return 0;
    }
    double decodeToDouble(char* arr){
        return 0.0;
    }
    DronePacket decodeInt(char* datafield){
    
    }

public:
    void setCompanyID(char* str){
        int size = strlen(str);
        if(strlen(str) >=8){
            for(int i =0 ; i<8; i++){
                company_id[i] = str[i];
            }
        }
        else{
            strcpy(company_id ,str);
            for(int i = size; i<8 ; i++){
                company_id[i] =' ';
            }
        }
    }
    void setDroneID(char* droneID){
        int size = strlen(droneID);
        if(strlen(droneID) >=8){
            for(int i =0 ; i<8; i++){
                drone_id[i] = droneID[i];
            }
        }
        else{
            strcpy(drone_id ,droneID);
            for(int i = size; i<8 ; i++){
                drone_id[i] =' ';
            }
        }
    }
    void setTimeStamp(char* str){
        if(strlen(str)!=12){
            std::cout<<"error: time stamp must be 12digits"<<std::endl;
            return;
        }
        else{
            strcpy(timeStamp,str);
        }
    }
    void setLatitude(double number){
        latitude = number;
    }
    void setLongitude(double number){
        longitude = number;
    }
    void setAltitude(double number){
        altitude = number;
    }
    void setLatitudeLongitudeAltitude(double lat, double lon, double alt){
        setLatitude(lat);
        setLongitude(lon);
        setAltitude(alt);    
    }
    void setState(int number){
        state = number;
    }
    void setMissionType(int number){
        mission_type = number;
    }
    void setMissionDetail(int number){
        mission_detail = number;
    }
    void setStateMissionTypeMissionDetail(int state, int type,int detail){
        setState(state);
        setMissionType(type);
        setMissionDetail(detail);
    }
    void setEmpty(int* arr){
        int size = sizeof(arr);
        if(size<sizeof(empty)){
            for(int i =0 ; i<size; i++){
                drone_id[i] = arr[i];
            }
        }
        else{
            std::cout<<"error: empty array size is too big..."<<std::endl;
            return;
        }
    }

    void calcSize(){
        /***우선은 empty 무시***/
        length =0;
        length += 4*4; //int 4개
        length += 5*8;
        length += 12;
        // length += 
    }

    void printData(){
        printf("PRINTING DRONE PACKET...\n");
        printf("Packet Length(byte) = %d\n",length);
        printf("Company ID = %s\n",company_id);
        printf("test = %d\n",strlen(company_id));
        printf("Drone ID = %s\n",drone_id);
        printf("latitude= %lf \n",latitude);
        printf("Longitude= %lf \n",longitude);
        printf("Altitude= %lf \n",altitude);
        printf("TimeStamp= %s\n",timeStamp);
        printf("state= %d\n",state);
        printf("mission_type= %d\n",mission_type);
        printf("mission_detail= %d\n",mission_detail);
        return;
    }

    void endcode(char*){

    }
    void decode(char*){

    }
    
};