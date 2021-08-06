#include <iostream>
#include<vector>

void serializeInteger(int number, char* data, int &loc)
{
    char* buffer = reinterpret_cast< char*>(&number);
    cout<<"::serializer::int send= [ ";
    for(int i =0 ;i<4;i++){
        cout<<(int)buffer[i]<<" ";
        data[loc++] = buffer[i];
    }
    cout<<']'<<endl;
}


void deserializeInteger(int &number, char* data, int &loc)
{
    char buffer[4];
    cout<<"::serializer::int received= [ ";
    for(int i =0 ;i<4;i++){
        buffer[i] = data[loc++];
        cout<<(int)buffer[i]<<" ";
    }
    cout<<']'<<endl;
    int result = *reinterpret_cast<int*>(buffer);
    number= result;
}

void serializeDouble(double number, char* data, int &loc)
{
    char* buffer = reinterpret_cast< char*>(&number);
    cout<<"::serializer::double send= [ ";
    for(int i =0 ;i<8;i++){
        cout<<(int)buffer[i]<<" ";
        data[loc++] = buffer[i];
    }
    cout<<']'<<endl;
}


void deserializeDouble(double &number, char* data, int &loc)
{
    char buffer[8];
    cout<<"::serializer::double received= [ ";
    for(int i =0 ;i<8;i++){
        buffer[i] = data[loc++];
        cout<<(int)buffer[i]<<" ";
    }
    cout<<']'<<endl;
    double result = *reinterpret_cast<double*>(buffer);
    number= result;
}

void serializeCharacter(char ch[], char* data, int &loc)
{
    cout<<"::serializer::char[] send= [ ";
    for(int i =0 ;i<8;i++){
        cout<<ch[i]<<" ";
        data[loc++] = ch[i];
    }
    cout<<']'<<endl;
}


void deserializeCharacter(char ch[], char* data, int &loc)
{
    char charBytes[8];
    cout<<"::serializer::char[] received= [ ";
    for(int i =0 ;i<8;i++){
        ch[i] = data[loc++];
        cout<<ch[i]<<" ";
    }
    cout<<']'<<endl;
}