/*
Your task is to:

    Use a union that overlays a uint32_t value with a 4-byte uint8_t array
    Read a 32-bit unsigned integer input
    Print its 4 individual bytes in little-endian order (i.e., LSB first)
    Assume the program runs on a little-endian machine.

Use only union access, no bit masking or shifts.


Example-1

Input: 305419896
Output: 120 86 52 18

(0x12345678 → bytes: 0x78 0x56 0x34 0x12)


Example-2

Input: 4294967295
Output: 255 255 255 255


Example-3

Input: 1
Output: 1 0 0 0
*/

#include <stdio.h>
#include <stdint.h>

typedef union{
    uint32_t reg;
    uint8_t bytes[4];
}Uni;

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

void print_uni(Uni u){
    for(int i = 0; i < 4 ; i++){
        printf("%u ", u.bytes[i]);
    }
}


int main(){
    uint32_t reg;
    scanf("%u", &reg);

    Uni U;

    U.reg = reg;

    print_uni(U);
    
    return 0;
}