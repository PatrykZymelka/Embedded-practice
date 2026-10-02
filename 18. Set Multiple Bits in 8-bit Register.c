/*
You are given an 8-bit register. Set all bits between position start and end (inclusive).

Use 0-based indexing and assume start <= end.


Example 1

Input: reg = 0b00000000, start = 1, end = 3 
Output: 0b00001110

Example 2

Input: reg = 0b00001000, start = 0, end = 2 
Output: 0b00001111

Example 3

Input: reg = 0b00000001, start = 3, end = 5 
Output: 0b00111001
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

void set_bits(uint8_t * reg, int start, int end){

    *reg |= ((1<<end-start+1)-1)<<start;

}


int main(){
    uint8_t reg;
    int start,end;
    scanf("%u %d %d",&reg, &start, &end);
    
    void * ptr = &reg;
    binary_visualization(ptr, 8);

    set_bits(&reg,start,end);

    binary_visualization(ptr, 8);

    return 0;
}