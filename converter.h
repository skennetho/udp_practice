#include <iostream>
#include<vector>

/*
unsigned char* DoubleToUnsignedChars(double number)
{
    unsigned char* charBytes = reinterpret_cast<unsigned char*>(&number);
    return charBytes;
}

double UnsignedCharsToDouble(unsigned char* charBytes)
{
    double result = *reinterpret_cast<double*>(charBytes);
    return result;
}

unsigned char* CharsToUnsignedChars(char* str)
{
    unsigned char* charBytes = reinterpret_cast<unsigned char*>(&str);
    return charBytes;
}


char* UnsignedCharsToChars(unsigned char* charBytes)
{
    char* result = reinterpret_cast<char*>(charBytes);
    return result;
}

char* IntToUnsignedChars(int number)
{
    char* charBytes = reinterpret_cast< char*>(&number);
    cout<<"charBytes send= [ ";
    for(int i =0 ;i<4;i++){
        cout<<(int)charBytes[i]<<" ";
    }
    cout<<']'<<endl;
    return charBytes;
}


int UnsignedCharsToInt( char* charBytes)
{
    cout<<"charBytes received= [ ";
    for(int i =0 ;i<4;i++){
        cout<<(int)charBytes[i]<<" ";
    }
    cout<<']'<<endl;
    int result = *reinterpret_cast<int*>(charBytes);
    return result;
}

vector<char>  IntToUnsignedChars_vector(int number)
{
    char* charBytes = reinterpret_cast< char*>(&number);
    vector<char> v;
    for (size_t i = 0; i < sizeof(int); ++i)
        v.push_back(charBytes[i]);
    return v;
}
int UnsignedCharsToInt_vector( vector<char> v)
{
    char charBytes[4];
    for (size_t i = 0; i < sizeof(int); ++i)
        charBytes[i] = v.at(i);
    int result = *reinterpret_cast<int*>(charBytes);
    return result;
}


const char* IntToUnsignedChars_const(int number)
{
    const char* charBytes = reinterpret_cast< char*>(&number);
    cout<<"charBytes send= [ ";
    for(int i =0 ;i<4;i++){
        cout<<(int)charBytes[i]<<" ";
    }
    cout<<']'<<endl;
    
    return charBytes;
}


int UnsignedCharsToInt_const(const char* charBytes)
{
    char arr[4];
    cout<<"charBytes received= [ ";
    for(int i =0 ;i<4;i++){
        cout<<(int)charBytes[i]<<" ";
        arr[i] = charBytes[i];
    }
    cout<<']'<<endl;
    
    int result = *reinterpret_cast<int*>(arr);
    return result;
}
*/

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