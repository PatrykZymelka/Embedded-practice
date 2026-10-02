/*
Given a 32-bit register, replace a few bits (starting at position pos) with a new value.

Only the targeted bits must change — others should stay unchanged.

 
Example 1

Input: reg = 0b1111 1111, val = 0b0000, pos = 4, len = 4  
Output: 0b0000 1111

Example 2

Input: reg = 0b0000 1111, val = 0b10, pos = 1, len = 2  
Output: 0b0000 1101
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

void replace_bits( uint32_t * reg, uint32_t val, int pos, int len){
    uint32_t mask = 0;
    mask |= ((1 << len)-1) << pos;
    *reg &= ~(mask);
    *reg |= (val << pos) & mask;

}

int main(){
    uint32_t reg, val;
    int pos, len;
    scanf("%u %u %d %d", &reg, &val, &pos, &len);

    void * ptr = &reg;

    binary_visualization(ptr, 32);

    replace_bits(&reg, val, pos, len);

    binary_visualization(ptr, 32);
    return 0;
}