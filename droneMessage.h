#include <iostream>

class DronePacket{
    //drone data
    int length;         //76byte ~ 128byte
    char company_id[8];
    char drone_id[8];
    double latitude;
    double longitude;
    double altitude;
    char time_stamp[12];
    int state;
    int mission_type;
    int mission_detail;
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
    int getSize(){

        return 0;
    }
};