#include <iostream>
#include<vector>

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

char* IntToUnsignedChars(int number)
{
     char* charBytes = reinterpret_cast< char*>(&number);
    return charBytes;
}

int UnsignedCharsToInt( char* charBytes)
{
    int result = *reinterpret_cast<int*>(charBytes);
    return result;
}

unsigned char* CharsToUnsignedChars(char* str)
{
    unsigned char* charBytes = reinterpret_cast<unsigned char*>(&str);
    return charBytes;
}

vector<char> CharsToUnsignedChars_vector(char* str)
{
    unsigned char* charBytes = reinterpret_cast<unsigned char*>(&str);
    vector<char> v;
    for (size_t i = 0; i < sizeof(double); ++i)
        v.push_back(charBytes[i]);
    return v;
}

char* UnsignedCharsToChars(unsigned char* charBytes)
{
    char* result = reinterpret_cast<char*>(charBytes);
    return result;
}

