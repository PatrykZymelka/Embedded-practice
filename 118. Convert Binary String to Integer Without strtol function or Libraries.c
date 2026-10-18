/*
In embedded systems, you may receive data as binary strings (e.g., "1101") via UART or user input, 
and need to convert it to an actual integer value — without using standard functions like strtol() or atoi().

Your task is to:

    Read a string of '0' and '1' characters (max length 16)
    Convert it to an unsigned integer
    You must not use any standard string conversion functions


Example-1

Input: 1010
Output: 10


Example-2

Input: 0001
Output: 1


Example-3

Input: 11111111
Output: 255


Example-4

Input: 0
Output: 0
*/

#include <stdio.h>
#include <stdint.h>

void binary_to_decimal(const char * binary, int * decimal){
    int i = 0;
    while(binary[i] != '\0'){
        *decimal |= ((binary[i] - '0') & 1);
        *decimal = (*decimal << 1);
        i++;
    }
    *decimal = (*decimal >> 1);
}

int main(){
    char binary[100];
    scanf("%s", &binary);
    int decimal;
    binary_to_decimal(binary, &decimal);
    
    printf("%d", decimal);
    return 0;
}