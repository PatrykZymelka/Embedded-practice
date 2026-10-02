/*
Your task is to:

    Read a uint16_t register value
    Extract the 5-bit field from bits 4 to 8 (LSB = bit 0)
    Return the value of that field as an unsigned integer
     

Example-1

Input: 0x01F0
Output: 31

(Binary = 0000 0001 1111 0000 → bits 4–8 are all 1)


Example-2

Input: 0x0000
Output: 0


Example-3

Input: 0x00B0
Output: 11

(Binary = 0000 0000 1011 0000 → bits 4–8 = 01011)
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

uint16_t extract_bits(uint16_t reg){
    uint16_t result = 0;
    result |= (reg >>4) & 0x1F;
    return result;
}


int main(){
    uint16_t reg,result;

    scanf("%u", reg);

    result = extract_bits(reg);

    void * ptr = &result;

    binary_visualization(ptr, 16);
    

    
    return 0;
}