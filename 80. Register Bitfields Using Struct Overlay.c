/*
You are implementing a simulated 8-bit control register where each bit controls a feature. 
Rather than using masks, you’ll use a bitfield struct to access individual bits.

The register layout is as follows:
Bit	Field	Size
0	enable	1
1–2	mode	2
3	interrupt	1
4–7	reserved	4

Your task is to:

    Define a union that overlays:
        A struct with bitfields: enable, mode, interrupt
        A raw uint8_t register
    Read values for enable, mode, interrupt from input
    Construct the struct, and print the final register as an 8-bit unsigned value

Assume:

    enable is 0 or 1
    mode ranges from 0–3
    interrupt is 0 or 1
     

Example-1

Input: 1 2 1
Output: 13

Explanation:

    Binary = 00001101 → enable=1, mode=10, interrupt=1
     

Example-2

Input: 0 0 1
Output: 8

Binary = 00001000
*/

#include <stdio.h>
#include <stdint.h>

typedef union{
    struct{
        uint8_t enable : 1;
        uint8_t mode : 2;
        uint8_t interrupt: 1;
        uint8_t reserved : 4;
    }fields;
    uint8_t reg;
}Un;

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
    uint8_t e, m, i;
    scanf("%hhu %hhu %hhu",&e,&m,&i);

    Un u;
    u.fields.enable = e;
    u.fields.mode = m;
    u.fields.interrupt = i;

    printf("%hhu\n", u.reg);
    
    return 0;
}