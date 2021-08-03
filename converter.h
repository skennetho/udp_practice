#include <iostream>

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

unsigned char* IntToUnsignedChars(int number)
{
    unsigned char* charBytes = reinterpret_cast<unsigned char*>(&number);
    return charBytes;
}

int UnsignedCharsToInt(unsigned char* charBytes)
{
    int result = *reinterpret_cast<int*>(charBytes);
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

