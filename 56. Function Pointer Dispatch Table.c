/*
You are building a simple math command handler. You are given two integers and a command code:

    0 → Add
    1 → Subtract
    2 → Multiply
    3 → Divide (integer division, assume non-zero)

 

Your task:

    Create an array of function pointers, each pointing to one of the above operations.
    Based on the command code, use the function pointer to invoke the correct operation.
    Return the result.
     

❌ No if-else or switch-case
✅ Must use a function pointer array
 

Example-1

Input: a = 10, b = 5, command = 0
Output: 15


Example-2

Input: a = 20, b = 8, command = 1
Output: 12


Example-3

Input: a = 6, b = 3, command = 3
Output: 2
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