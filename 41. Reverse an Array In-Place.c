/*
You are given an array of integers and its length. Write a function to reverse the array in-place, without using another array.


Example-1

Input:  n = 5, arr = [1 2 3 4 5]  
Output: [5 4 3 2 1]

Example-2

Input:  n = 4, arr = [10 20 30 40]  
Output: [40 30 20 10]
*/

#include <stdio.h>
#include <stdint.h>
#pragma pack(1)

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
    
    
    return 0;
}