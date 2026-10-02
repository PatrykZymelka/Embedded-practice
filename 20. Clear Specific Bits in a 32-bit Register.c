/*
You are given a 32-bit control register. Clear a group of bits (set them to 0) starting at a given position and length.

Other bits must stay untouched.


Example 1

Input: reg = 0b1111 1111, pos = 4, len = 4 
Output: 0b0000 1111

Example 2 

Input: reg = 0b0000 1111, pos = 0, len = 2 
Output: 0b0000 1100
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

void clear_32bits_reg(uint32_t * reg, int pos, int len){
    *reg &= ~(((1<<len)-1) << pos);
}

int main(){
    uint32_t reg;
    int pos,len;
    scanf("%u %d %d", &reg, &pos, &len);

    void * ptr = &reg;
    binary_visualization(ptr, 32);

    clear_32bits_reg(&reg, pos, len);

    binary_visualization(ptr, 32);

    return 0;
}