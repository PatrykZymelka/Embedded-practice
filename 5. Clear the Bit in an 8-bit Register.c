/*
You are working with an 8-bit control register. Write a function to clear (set to 0) the bit at a given position without affecting other bits.

Use 0-based indexing for bit positions (0 = LSB, 7 = MSB).


Example 1

Input: reg = 0b00000111, pos = 0 
Output: 0b00000110


Example 2

Input: reg = 0b00001111, pos = 3 
Output: 0b00000111
*/

#include <stdio.h>
#include <stdint.h>

void clear_bit(uint8_t * reg, int pos){
    *reg &= ~(1 << pos);
}

int main(){
    uint8_t reg;
    int pos;
    scanf("%u %d", &reg, &pos);
    clear_bit(&reg,pos);
    printf("%u\n", reg);
    return 0;
}