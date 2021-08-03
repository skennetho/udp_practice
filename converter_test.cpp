#include<iostream>
#include<algorithm>
#include "droneMessage.h"

int CharsToInt(unsigned char* charBytes);
unsigned char* IntToChars(int number);
void testIntAndCharsConverter(double number);
unsigned char* DoubleToChars(double number);
double CharsToDouble(unsigned char* charBytes);

int main(int args, char **argv)
{
//참고: https://stackoverflow.com/questions/3784263/converting-an-int-into-a-4-byte-char-array-c

    // if (args != 2){
    //     printf("error: arguments must be 2\n");
    //     return 1;
    // } 
    
    char* str = "AWESOME ";
    unsigned char* bytes =CharsToUnsignedChars(str);
    char* result = UnsignedCharsToChars(bytes);

    printf("%s \n", str);
    printf("%s \n", result);

    int int1 = 231;
    unsigned char* bytes1 =IntToChars(int1);
    int result1 = CharsToInt(bytes1);

    printf("%d \n", int1);
    printf("%d \n", result1);

    double double1 = 16.123456;
    unsigned char* bytes2 =DoubleToChars(double1);
    double result2 = CharsToDouble(bytes2);

    printf("%lf \n", double1);
    printf("%lf \n", result2);

    return 0;
}

void testIntAndCharsConverter(int number)
{
    int num1 = 255;
    unsigned char* byteArray = reinterpret_cast<unsigned char*>(&num1);
    int final1 = *reinterpret_cast<int*>(byteArray);

    
    printf("before= %d, after = %d \n",num1,final1);
}


unsigned char *DoubleToChars(double number)
{
    unsigned char* charBytes = reinterpret_cast<unsigned char*>(&number);
    return &charBytes[0];
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
