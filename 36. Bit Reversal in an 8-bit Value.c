/*
You are given an 8-bit unsigned integer. Your task is to:

    Reverse the order of its bits
    Print the resulting 8-bit value (in decimal)

You must not use any lookup table or standard library function. Use pure bitwise logic.


Example-1

Input: val = 0b00011010
Output: 0b01011000 → Decimal: 88


Example-2

Input: val = 0b10110000
Output: 0b00001101 → Decimal: 13


Example-3

Input: val = 255
Output: 255 (All bits reversed remain the same)
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

uint8_t reverse_binary(uint8_t reg){
    uint8_t result = 0;

    for(int i = 0; i < 8; i++){

        int val = (reg << i) & 0x80;
        if(val != 0){
            result |= (1 << i);
        }
    }
    return result;

}

int main(){
    uint8_t reg;
    scanf("%u", &reg);

    void * ptr = &reg;
    binary_visualization(ptr, 8);

    uint8_t result = reverse_binary(reg);

    ptr = &result;
    binary_visualization(ptr, 8);
    
    return 0;
}