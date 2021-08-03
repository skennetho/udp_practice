#include<iostream>

int CharsToInt(unsigned char* char_bytes);
unsigned char* IntToChars(int number);
void testIntAndCharsConverter(int number);

int main(int args, char **argv)
{
//참고: https://stackoverflow.com/questions/3784263/converting-an-int-into-a-4-byte-char-array-c

    if (args != 2){
        printf("error: arguments must be 2\n");
        return 1;
    }
    
    int number = atoi(argv[1]);
    testIntAndCharsConverter(number);


    return 0;
}

void testIntAndCharsConverter(int number)
{
    unsigned char* chars;
    chars = IntToChars(number);
    int result = CharsToInt(chars);


    printf("before: %d , after: %d \n", number, result);
}
unsigned char* IntToChars(int number)
{
    unsigned char* char_bytes;

    char_bytes[0] =(number>> 24) & 0xFF;
    char_bytes[1]=(number>> 16) & 0xFF;
    char_bytes[2]=(number>> 8) & 0xFF;
    char_bytes[3]=number& 0xFF;
    
    return char_bytes;
}

int CharsToInt(unsigned char* char_bytes)
{
    int result;
    result  = int((unsigned char)(char_bytes[0]) << 24 |
            (unsigned char)(char_bytes[1]) << 16 |
            (unsigned char)(char_bytes[2]) << 8 |
            (unsigned char)(char_bytes[3]));
    return result;
}
