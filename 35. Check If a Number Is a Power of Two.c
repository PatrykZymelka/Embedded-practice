/*
Write a function to check if a given positive integer is a power of 2. Do not use loops, multiplication, division, or library functions.
You must solve it using bitwise logic only.

 

Example-1

Input:  n = 8  
Output: YES


Example-2

Input:  n = 7  
Output: NO


Example-3

Input:  n = 1  
Output: YES
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

int is_power_of_two(uint32_t reg){
    if(reg == 0){
        return 0;
    }
    uint32_t temp = reg;
    for(int i = 0; i < 32; i++){
        temp &= ~(1 << i);
        if(temp != reg && temp != 0){
            return 0;
        }
    }
    return 1;
}


int main(){
    uint32_t reg;
    scanf("%u", &reg);

    int result = is_power_of_two(reg);

    if(result == 1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    
    return 0;
}