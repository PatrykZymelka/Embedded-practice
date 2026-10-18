/*
In embedded development, visualizing the binary form of a value is crucial for debugging and understanding register configuration. Your task is to:

    Read an unsigned integer (8-bit or 16-bit)
    Print its binary representation, padded with leading zeros
    Length must be 8 bits (if input ≤ 255) or 16 bits otherwise 


Example-1

Input: val = 10
Output: 00001010


Example-2

Input: val = 255
Output: 11111111


Example-3

Input: val = 1023
Output: 0000001111111111


Example-4

Input: val = 65535
Output: 1111111111111111
*/

#include <stdio.h>
#include <stdint.h>

void binary_visualisation(uint16_t n){
    int count;
    if(n > 255){
        count = 16;
    }
    else{
        count = 8;
    }
    for(int i = count-1; i >=0;i--){
        if((n>>i) & 1){
            printf("1");
        }
        else{
            printf("0");
        }
    }
}

int main(){
    uint16_t n;
    scanf("%hu",&n);

    binary_visualisation(n);
    
    return 0;
}