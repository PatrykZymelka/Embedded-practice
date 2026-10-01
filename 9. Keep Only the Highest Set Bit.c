/*
You are given a 16-bit register (uint16_t).
Your task is to:

    Return a value where only the highest (leftmost) set bit is retained
    All other bits must be cleared


Example-1

Input:  44        // Binary: 0000000000101100  
Output: 32        // Binary: 0000000000100000

Example-2

Input:  512       // Binary: 0000001000000000  
Output: 512       // Binary: 0000001000000000

Example-3

Input:  255       // Binary: 0000000011111111  
Output: 128       // Binary: 0000000010000000
*/

#include <stdio.h>
#include <stdint.h>

uint16_t keep_the_highest_bit(uint16_t * reg){
    if((*reg) == 0){
        return 0;
    }
    int i = 0;
    uint16_t result = 0;
    while((*reg>>i) != 0){
        i++;
    }
    return result |= (1 << i-1);

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
    uint16_t reg = 0;
    scanf("%u", &reg);
    void * ptr = &reg;
    binary_visualization(ptr, 16);

    uint16_t result = keep_the_highest_bit(&reg);
    ptr = &result;
    
    binary_visualization(ptr, 16);
    return 0;


}