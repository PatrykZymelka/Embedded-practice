/*
In embedded systems, modifying specific bits of control or status registers is a frequent task. You’re given an 8-bit register (uint8_t) and must perform the following bit operations on it:

    Set bits 2 and 7
    Clear bit 3
    Toggle bit 5

Your task is to implement a function that:

    Accepts a uint8_t reg as input
    Applies all the above operations in the given order
    Returns the updated register value

Use proper bitwise macros for maintainability.

 

Example-1

Input: 0
Output: 164

(00000000 → 10100100)

Example-2

Input: 255
Output: 215

(11111111 → Set 2 & 7 → already set, Clear 3 → unset bit 3, Toggle 5 → flip bit 5 → becomes 0)

Example-3

Input: 36
Output: 132

(00100100 → Toggle 5 → cleared, Clear 3 → already clear, Set 2 and 7 → becomes 10000100)
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

void macro(uint8_t * reg){
    *reg |= (1 << 2) | (1 << 7);
    *reg &= ~(1 << 3);
    *reg ^= (1<< 5);
}

int main(){
    uint8_t reg = 0;
    scanf("%u", &reg);
    void * ptr = &reg;
    binary_visualization(ptr, 32);

    macro(&reg);

    binary_visualization(ptr, 32);

    return 0;


}