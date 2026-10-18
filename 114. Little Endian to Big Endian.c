/*
In embedded systems, communication between processors may require byte-order conversion. You are given a 32-bit unsigned integer stored in little-endian format.

Your task is to convert this value to big-endian by swapping its bytes, and print the result.
 

Example-1

Input: 305419896
Output: 2018915346

(0x12345678 → 0x78563412)


Example-2

Input: 1
Output: 16777216

(0x00000001 → 0x01000000)


Example-3

Input: 0xAABBCCDD
Output: 0xDDCCBBAA → 3721182122
*/

#include <stdio.h>
#include <stdint.h>

typedef union{

    uint32_t reg;
    uint8_t bytes[4];

}Uni;

int main(){
    Uni u;
    scanf("%u",&u.reg);
    uint32_t result = 0;
    for(int i = 0; i < 4; i ++){
        result |= (u.bytes[i] << (8*(3-i)));
    }
    printf("%d\n", result);
    
    return 0;
}