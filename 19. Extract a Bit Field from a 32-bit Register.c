/*
You are working with a 32-bit hardware status register. Extract a few bits from it, starting from a given bit position and covering a given length. Return the extracted value as an unsigned integer.


Use 0-based indexing (LSB = position 0).


Example 1

Input: reg = 0b1011 0110 0111 0000 0000 0000 0000 0000, pos = 28, len = 4 
Output: 0b1011

Example 2

Input: reg = 0b0000 0000 0000 0000 0000 0000 1111 1111, pos = 0, len = 8  
Output: 0b11111111
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

uint32_t extract_32bit_register(uint32_t reg, int pos, int len){
    uint32_t result = 0;

    result = (reg >> pos) & ((1 << len)-1);

    return result;
}

int main(){
    uint32_t reg;
    int pos,len;
    scanf("%u %d %d", &reg, &pos, &len);

    void * ptr = &reg;
    binary_visualization(ptr, 32);

    uint32_t result = extract_32bit_register(reg, pos, len);

    ptr = &result;
    binary_visualization(ptr, 32);


    return 0;
}