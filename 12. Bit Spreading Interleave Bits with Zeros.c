/*
In some protocols or hardware applications (e.g. graphic rendering, signal encoding), bit spreading or interleaving is used to insert 0s between the bits of a value for purposes like data alignment or transmission.

You are given an 8-bit number, and your task is to:

    Spread the bits such that each bit is followed by a 0
    The result will be a 16-bit number where each original bit occupies even positions (0, 2, 4…)
    All odd positions are 0s


Example Logic

Original (8-bit):

b7 b6 b5 b4 b3 b2 b1 b0

Spreading result (16-bit):

0 b7 0 b6 0 b5 0 b4 0 b3 0 b2 0 b1 0 b0



Example-1

Input: val = 0b11001010 (Decimal 202)
Output: 0b0101000001000100 → Decimal: 20548

Example-2

Input: val = 0b10101010
Output: 0b0100010001000100 → Decimal: 17476

Example-3

Input: val = 0b11111111
Output: 0b0101010101010101 → Decimal: 21845
*/

#include <stdio.h>
#include <stdint.h>


void binary_visualization(void * reg, int bit_len){
     
    switch(bit_len){
        case 8:
            uint8_t regist1 = *((uint8_t*)reg); 
            for(int i = 7; i >=0; i--){
                printf("%d",(regist1 >> i) & 1); 
            }
            break;
        case 16:
            uint16_t regist2 = *(uint16_t*)reg; 
            for(int i = 15; i >=0; i--){
                printf("%d",(regist2 >> i) & 1); 
            }
            break;
        case 32:
            uint32_t regist3 = *(uint32_t*)reg; 
            for(int i = 31; i >=0; i--){
                printf("%d",(regist3 >> i) & 1); 
            }
            break; 
        }
    printf("\n");
}

uint16_t bit_spreading(uint8_t reg){
    uint16_t result = 0;

    for(int i = 0;i<16;i+=2){
        result |= ((reg & (1<<i/2)) ? 1 : 0) << i;
    }

    return result;
}

int main(){
    uint8_t reg = 0;
    scanf("%u", &reg);
    void * ptr = &reg;
    binary_visualization(ptr, 8);

    uint16_t result = bit_spreading(reg);
    ptr = &result;
    binary_visualization(ptr, 16);

    return 0;


}