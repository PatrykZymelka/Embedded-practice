/*
In the previous problem, we interleaved an 8-bit number into a 16-bit value by inserting 0s between each bit. Now your task is to:

    Reverse the interleaving process
    Extract only the bits from even-numbered positions in a 16-bit number
    Reconstruct the original 8-bit value
     

Example Logic

16-bit input:

[b15 b14 ... b1 b0]

Extract bits at positions: 0, 2, 4, 6, 8, 10, 12, 14 → and shift into:

b0 b1 b2 b3 b4 b5 b6 b7

 

Example-1

Input: val = 20548 → Binary: 0101000001000100
Output: 202 (Binary: 11001010)


Example-2

Input: val = 21845 → Binary: 0101010101010101
Output: 255 (Binary: 11111111)


Example-3

Input: val = 1 → Binary: 0000000000000001
Output: 1
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

uint8_t compress_bits(uint16_t reg){

    uint8_t result = 0;

    for(int i = 0; i<8;i++){
        result |= ((reg >> (i*2)) & 1) << i;
    }

    return result;

}

int main(){
    uint16_t reg;

    scanf("%u", &reg);

    void * ptr = &reg;
    binary_visualization(ptr, 16);

    uint8_t result = compress_bits(reg);

    ptr = &result;
    binary_visualization(ptr, 8);
    
    return 0;
}