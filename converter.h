#include <iostream>

unsigned char* DoubleToChars(double number)
{
    unsigned char* charBytes = reinterpret_cast<unsigned char*>(&number);
    return charBytes;
}

double CharsToDouble(unsigned char* charBytes)
{
    double result = *reinterpret_cast<double*>(charBytes);
    return result;
}

unsigned char* IntToChars(int number)
{
    unsigned char* charBytes = reinterpret_cast<unsigned char*>(&number);
    return charBytes;
}

int CharsToInt(unsigned char* charBytes)
{
    int result = *reinterpret_cast<int*>(charBytes);
    return result;
}
