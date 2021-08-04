#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

class DronePacket{
private:
    int length;         //76byte ~ 128byte
    char drone_id[8];   //8byte
    double latitude;    //8byte
    double longitude;   //8byte
    double altitude;    //8byte
    char timeStamp[12]; //12byte
    int state;          //4byte
    int mission_type;   //4byte
    int mission_detail; //4byte
    // int empty[13];      //52byte 13 numbers
    vector<int> empty;  //13numbers maximum.
    char company_id[8]; //8byte       


public:
    DronePacket()
    {
        strcpy(company_id, "com___id");
        strcpy(drone_id, "drone_id" );
        latitude = 36.35111;    // Daejeon city's lat&lon
        longitude = 127.38500;
        altitude =  0;
        strcpy(timeStamp ,"00.00.00.000" );
        state =0;
        mission_detail =0;
        mission_type =0;
        calcSize();
    }

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

    void setEmpty(vector<int> arr){
        if(arr.size() <=13){
            empty = arr;
            calcSize();
        }
        else{
            std::cout<<"error: empty array size is too big..."<<std::endl;
            return;
        }
    }

    void calcSize(){
        length =4;  // init with header length
        length += 4*4; 
        length += 5*8;
        length += 12;
        length += empty.size()*4;
        if(length >=156 ){
            printf("warning: drone packet's length must be less than 156");
            
        }

    }
    int getSize(){
        return length;
    }

    void printData(){
        calcSize();
        printf("PRINTING DRONE PACKET...\n");
        printf("Packet Length(byte) = \t%d\n",length);
        printf("Company ID = \t\t%s\n",company_id);
        printf("Drone ID = \t\t%s\n",drone_id);
        printf("latitude= \t\t%lf \n",latitude);
        printf("Longitude= \t\t%lf \n",longitude);
        printf("Altitude= \t\t%lf \n",altitude);
        printf("TimeStamp= \t\t%s\n",timeStamp);
        printf("state= \t\t\t%d\n",state);
        printf("mission_type = \t\t%d\n",mission_type);
        printf("mission_detail= \t%d\n",mission_detail);
        cout<<"empty = [ ";
        for_each(empty.begin(), empty.end(), [&](int& n){
            cout << n << " ";        //output  참조:https://hwan-shell.tistory.com/119
        });
        cout<<"]"<<endl;
        return;
    }

    //serialize
    void serialize(char* da){
        calcSize();
        if(length >=156 ){
            return;
        }

        unsigned char data[length];
        int index =0;

        unsigned char* bytesLen = reinterpret_cast<unsigned char*>(&length);        //length: int
        for(int i =0 ; i< 4; i++){
            data[index++] = bytesLen[i];
        } 

        for(int i =0; i<8 ; i++){                                                   //company_id: char[8]
            data[index++] = company_id[i];
        }

        for(int i =0; i<8 ; i++){                                                   //drone_id: char[8]
            data[index++] = drone_id[i];
        }
        
        unsigned char* bytesLat = reinterpret_cast<unsigned char*>(&latitude);      //latitude: double
        for(int i =0 ; i< 8; i++){
            data[index++] = bytesLat[i];
        } 

        unsigned char* bytesLon = reinterpret_cast<unsigned char*>(&longitude);     //longitude: double
        for(int i =0 ; i< 8; i++){
            data[index++] = bytesLon[i];
        } 

        unsigned char* bytesAlt = reinterpret_cast<unsigned char*>(&altitude);      //altitude: double
        for(int i =0 ; i< 8; i++){
            data[index++] = bytesAlt[i];
        } 
        
        for(int i =0 ; i< 12; i++){                                                 //timestamp: char[12]
            data[index++] = timeStamp[i];
        } 

        unsigned char* bytesState = reinterpret_cast<unsigned char*>(&state);       //state: int
         for(int i =0 ; i< 4; i++){
            data[index++] = bytesState[i];
        } 

        unsigned char* bytesMType = reinterpret_cast<unsigned char*>(&mission_type);    //mission_type: int
         for(int i =0 ; i< 4; i++){
            data[index++] = bytesMType[i];
        } 

        unsigned char* bytesMDetail = reinterpret_cast<unsigned char*>(&mission_detail);//mission_detail: int
         for(int i =0 ; i< 4; i++){
            data[index++] = bytesMDetail[i];
        } 

        for(int i=0; i< empty.size(); i++){                                             //empty: max 52byte == 13 integer
            char* byte = reinterpret_cast<char*>(&empty.at(i));
            for(int j =0 ; j< 4; j++){
                data[index++] = byte[j];
            } 
        }
        da = reinterpret_cast<char*>(data);
    }
    //deserialize
    void deserialize(char* da){
        unsigned char bufferDouble[8];
        unsigned char bufferInt[4];
        int index=0;
        
        unsigned char *data = reinterpret_cast<unsigned char*>(da);

        for(int i=0; i <4; i++){                                                    //length
            bufferInt[i] = data[index++];
        }
        length = *reinterpret_cast<int*>(bufferInt);

        for(int i =0 ; i<8 ; i++){                                                  //company_id
            company_id[i] = data[index++];
        }

        for(int i =0 ; i<8 ; i++){                                                  //drone_id
            drone_id[i] = data[index++];
        }

        for(int i=0; i <8; i++){                                                    //latitude
            bufferDouble[i] = data[index++];
        }
        latitude = *reinterpret_cast<double*>(bufferDouble);

        for(int i=0; i <8; i++){                                                    //longitude
            bufferDouble[i] = data[index++];
        }
        longitude = *reinterpret_cast<double*>(bufferDouble);

        for(int i=0; i <8; i++){                                                    //altitude
            bufferDouble[i] = data[index++];
        }
        altitude = *reinterpret_cast<double*>(bufferDouble);

        for(int i =0 ; i<12 ; i++){                                                 //timestamp
            timeStamp[i] = data[index++];
        }
        
        for(int i=0; i <4; i++){                                                    //state
            bufferInt[i] = data[index++];
        }
        state = *reinterpret_cast<int*>(bufferInt);

        for(int i=0; i <4; i++){                                                    //mission type
            bufferInt[i] = data[index++];
        }
        mission_type = *reinterpret_cast<int*>(bufferInt);

        for(int i=0; i <4; i++){                                                    //mission_detail
            bufferInt[i] = data[index++];
        }
        mission_detail = *reinterpret_cast<int*>(bufferInt);

        empty.clear();                                                              //empty
        for(;index<length;){
            for(int i =0; i<4; i++){
                bufferInt[i] = data[index++];
            }
            int num = *reinterpret_cast<int*>(bufferInt);
            empty.push_back(num);
        }

        // if (length != index){                                                       //길이가 안맞으면 패쓰.
        //     printf("error: packet lost.. length doesn't match");
        //     return;
        // }
    }
    
};