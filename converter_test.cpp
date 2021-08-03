#include<iostream>
#include<algorithm>

int CharsToInt(unsigned char* charBytes);
unsigned char* IntToChars(int number);
void testIntAndCharsConverter(double number);
double CharsToDouble(unsigned char* charBytes);
unsigned char* DoubleToChars(double number);

int main(int args, char **argv)
{
//참고: https://stackoverflow.com/questions/3784263/converting-an-int-into-a-4-byte-char-array-c

    // if (args != 2){
    //     printf("error: arguments must be 2\n");
    //     return 1;
    // } 
    
    int a = 1452345;
    int *ptr;
    ptr = reinterpret_cast<int*> (a);
    // printf("%d, %d\n", a, *ptr);
    // printf("%d, %d\n", &a, ptr);
    

    return 0;
}

void testIntAndCharsConverter(int number)
{
    int num1 = 255;
    unsigned char* byteArray = reinterpret_cast<unsigned char*>(&num1);
    int final1 = *reinterpret_cast<int*>(byteArray);

    
    printf("before= %d, after = %d \n",num1,final1);
}


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
