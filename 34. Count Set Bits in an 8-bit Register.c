/*
You are given an 8-bit register. Count how many bits are set to 1 (i.e., high) in the register.


Example 1

Input: reg = 0b0000 1111 
Output: 4


Example 2

Input: reg = 0b1111 0000 
Output: 4


Example 3

Input: reg = 0b0000 0000 
Output: 0


Example 4 

Input: reg = 0b1111 1111 
Output: 8
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

int count_set_bits(uint8_t reg){

    int count = 0;
    for(int i = 0; i < 8; i++){
        if((reg >> i) & 1U){
            count++;
        }
    }

    return count;
}


int main(){

    uint8_t reg;
    scanf("%u", &reg);
    int result = count_set_bits(reg);
    printf("%d",result);
    
    return 0;
}