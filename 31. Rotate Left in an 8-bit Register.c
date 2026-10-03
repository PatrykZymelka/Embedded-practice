/*
You are given an 8-bit register and a number of positions n. Rotate the register to the left by n bits. The rotation must be circular, meaning the leftmost bits wrap around to the right.

Use 0-based indexing, and return the result as an 8-bit value.


Example 1

Input: reg = 0b1011 0000, n = 1 
Output: 0b0110 0001


Example 2

Input: reg = 0b1000 0001, n = 2 
Output: 0b0000 0110


Example 3

Input: reg = 0b1111 1111, n = 4 
Output: 0b1111 1111
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


void rotate_left(uint8_t * reg, int n){

    *reg = ((*reg) << n) | ((*reg) >> (8-n));

}

int main(){
    uint8_t reg;
    int n;
    scanf("%u %d",&reg, &n);

    void * ptr = &reg;
    binary_visualization(ptr, 8);

    rotate_left(&reg, n);
    
    binary_visualization(ptr, 8);

    return 0;
}