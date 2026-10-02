/*
From a 32-bit register, extract all even-positioned bits (0, 2, 4, …, 30).

Return the compressed value formed by only these bits (shifted to be consecutive).


Example 1

Input: reg = 0b0101 0101 
Output: 0b1111

Example 2 

Input: reg = 0b1010 1010 
Output: 0b0000
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

uint16_t even_bits(uint32_t reg){
    uint16_t result = 0;
    for(int i = 0; i < 16;i++){
        result |= (((reg >> i*2) & 1) << i);
    }
    return result;
}

int main(){
    uint32_t reg;
    scanf("%u", &reg);

    void * ptr = &reg;
    binary_visualization(ptr, 32);

    uint16_t result = even_bits(reg);

    ptr = &result;

    binary_visualization(ptr, 16);

    return 0;
}