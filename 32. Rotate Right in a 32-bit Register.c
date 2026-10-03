/*
You are given a 32-bit hardware register and a number n. Rotate the register to the right by n bits in a circular fashion.
The bits shifted out on the right should reappear on the left.

Example 1

Input: reg = 0b0000 0000 0000 0000 0000 0000 0000 1111,  n = 4 
Output: 0b1111 0000 0000 0000 0000 0000 0000 0000


Example 2 

Input: reg = 0b0000 0000 0000 0000 0000 0000 0000 0001, n = 1 
Output: 0b1000 0000 0000 0000 0000 0000 0000 0000


Example 3

Input: reg = 0b1000 0000 0000 0000 0000 0000 0000 0000, n = 2 
Output: 0b0010 0000 0000 0000 0000 0000 0000 0000
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

void rotate_right(uint32_t * reg, int n){

    *reg = (*reg >> n) | (*reg << (32-n));

}


int main(){
    uint32_t reg;
    int n;
    scanf("%u %d", &reg, &n);

    void * ptr = &reg;
    binary_visualization(ptr, 32);

    rotate_right(&reg, n);

    binary_visualization(ptr, 32);


    
    return 0;
}