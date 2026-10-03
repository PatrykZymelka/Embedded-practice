/*
You are given a 16-bit register and a target pattern (also 16-bit). Check if the target pattern can be matched by any circular rotation of the register.
 

Example 1

Input: reg = 0b1011 0000 0000 0000, target = 0b0000 0000 0000 1011  
Output: 1 (matches after left rotation by 13)


Example 2 

Input: reg = 0b1000 0000 0000 0001, target = 0b0000 0000 0000 1100  
Output: 1


Example 3 

Input: reg = 0b1111 1111 1111 1111, target = 0b1111 1111 1111 0111  
Output: 0
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

int circular_pattern(uint16_t reg, uint16_t val){

    for(int i = 0; i < 16; i++){
        if(reg == val){
            return 1;
        }
        reg = (reg >> 1) | (reg << (16-1));
    }
    return 0;

}

int main(){
    uint16_t reg, val;
    scanf("%u %u", &reg, &val);
    int result = circular_pattern(reg,val);
    printf("%d",result);
    
    return 0;
}