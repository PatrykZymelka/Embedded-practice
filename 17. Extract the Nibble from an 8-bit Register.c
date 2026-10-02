/*
Write a C program to extract a nibble (4-bit value) from an 8-bit register.

    The user provides an 8-bit integer (register value) and a nibble position (0 for lower nibble, 1 for upper nibble).
    Your task is to extract and print the nibble’s decimal value.

Input Format

    An 8-bit integer (0-255) representing the register value.
    A nibble position (0 for lower, 1 for upper).

Output Format

    The extracted 4-bit value (0-15).

 

Example-1

Input: reg = 0xAB, pos = 0
Output: 11
(0xAB → lower nibble = 0xB = 11)

Example-2

Input: reg = 0xAB, pos = 1
Output: 10
(0xAB → upper nibble = 0xA = 10)

Example-3

Input: reg = 0xFF, pos = 0
Output: 15
*/

#include <stdio.h>
#include <stdint.h>

int extract_nibble(uint8_t reg, int pos){
    int result = 0;
    if(pos == 1){
        result = (reg >> 4) & 0xF;
    }
    else{
        result = (reg & 0xF);
    }

    return result;
}

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



int main(){
    uint8_t reg;
    int pos;
    scanf("%u %d", &reg, &pos);
    printf("%d\n", extract_nibble(reg,pos));

    return 0;
}