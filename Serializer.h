#include<iostream>
#include <string.h>

using namespace std;

void serializeInteger(char data[], int &num, int &index){
    static char* intBuffer = reinterpret_cast< char*>(&num);
    char da[4];
    for(int i =0 ; i< 4; i++){
        da[index++] = intBuffer[i];
    } 
    memcpy(data,da,sizeof(da));
}

void deserializeInteger(char data[], int &num, int &index){
    char intBuffer[4];
    for(int i=0; i <4; i++){
        cout<<'='<<(int)data[index]<<endl;
        intBuffer[i] = data[index++];
    }
    num = *reinterpret_cast<int*>(intBuffer);
}
