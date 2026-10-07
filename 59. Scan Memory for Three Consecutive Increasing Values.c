/*
You are given a block of memory (as an integer array) of size n.

Your task is to write a function that scans the memory using pointers and detects the first occurrence of three consecutive increasing integers — for example: [4, 5, 6] or [10, 11, 12].

Return the starting index of the first such pattern. If no such pattern is found, return -1.You must use pointer logic only, not array indexing.
 

Example-1

Input: n = 8, memory = [2, 4, 5, 6, 9, 11, 12, 14]
Output: 1


Example-2

Input: n = 6, memory = [10, 20, 30, 40, 50, 60]
Output: -1


Example-3

Input: n = 7, memory = [1, 2, 3, 5, 6, 7, 8]
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



int main(){

    
    return 0;
}