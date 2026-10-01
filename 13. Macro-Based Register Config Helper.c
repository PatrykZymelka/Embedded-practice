/*
In embedded systems, registers are often configured by setting specific bits. To make the code cleaner and reusable, firmware developers use macros to set fields in a register.

You are given a 16-bit control register layout:
Field	Bits	Position (LSB-first)
ENABLE	1	Bit 0
MODE	2	Bits 1–2
SPEED	3	Bits 3–5
RESERVED	2	Bits 6–7 (must be 0)

Your task is to:

    Write macros to:
        Set the ENABLE bit
        Set the MODE field
        Set the SPEED field
    Read ENABLE, MODE, SPEED from input
    Use the macros to pack a final 16-bit register value
    RESERVED bits (6–7) must be left 0


Example-1

Input: enable = 1, mode = 2, speed = 4
Output: 37
(Binary: 0000 0000 0010 0101)

Example-2

Input: enable = 0, mode = 1, speed = 3
Output: 26
(Binary: 0000 0000 0001 1010)
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

void macro(uint16_t * reg, int enable, int mode, int speed){
    *reg |= (enable << 0);
    *reg |= (mode << 1);
    *reg |= (speed << 3);
}

int main(){
    uint16_t reg = 0;
    
    void * ptr = &reg;
    binary_visualization(ptr, 16);

    int enable, mode, speed;
    scanf("%d %d %d", &enable, &mode, &speed);

    macro(&reg, enable, mode, speed);

    binary_visualization(ptr, 16);

    return 0;


}