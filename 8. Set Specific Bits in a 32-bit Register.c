/*
You are working with a 32-bit configuration register. Set a few bits starting from a given position and covering a specific length. The bits must be set to 1 (ON), without affecting other bits in the register.

Use 0-based indexing.


Example 1

Input: reg = 0b0000 0000 0000 0000 0000 0000 0000 0000, pos = 4, len = 3  
Output: 0b0000 0000 0000 0000 0000 0000 0111 0000

Example 2

Input: reg = 0b0000 0000 0000 0000 0000 0000 0000 0001, pos = 1, len = 2  
Output: 0b0000 0000 0000 0000 0000 0000 0000 0111
*/
#include <stdio.h>
#include <stdint.h>

void set_bit(uint32_t * reg, int pos, int len){

    uint32_t mask = 0;
    mask |= ((1 << len)-1) << pos;

    *reg |= mask;
}

int main(){

    uint32_t reg;
    int pos;
    int len;

    scanf("%u %d %d", &reg,&pos,&len);
    set_bit(&reg, pos, len);
    printf("%u",reg);



}