#include<iostream>
#include<string>
#include "Serializer.h"
#include "converter.h"
using namespace std;


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

void test_converter(){
    int num = 234;
    char* data_raw;
    data_raw = reinterpret_cast<char*>(&num);
    cout<<"data_raw= [ ";
    for(int i =0 ;i<4;i++){
        cout<<(int)data_raw[i]<<" ";
    }
    cout<<']'<<endl;
    num = *reinterpret_cast<int*>(data_raw);
    cout<<"data_raw = "<<num<<endl;

    v
     char* data_fun;
    data_fun = IntToUnsignedChars(num);
    cout<<"data_fun= [ ";
    for(int i =0 ;i<4;i++){
        cout<<(int)data_fun[i]<<" ";
    }
    cout<<']'<<endl;
    num = UnsignedCharsToInt(data_fun);
    cout<<"data_fun = "<<num<<endl;
    
}


int main(){
    test_converter();
    
    return 0;
}