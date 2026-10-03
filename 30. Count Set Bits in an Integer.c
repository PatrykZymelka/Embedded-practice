/*
Write a C program to count the number of set bits (1s) in the binary representation of an integer N.

Input Format

    A single integer N.

Output Format

    Print the count of set bits.

Here are the examples for Count Set Bits in an Integer:

 

Example-1

Input: 5
Output: 2 (Binary: 101)

Example-2

Input: 0
Output: 0 (Binary: 0000)

Example-3

Input: 15
Output: 4 (Binary: 1111)

Example-4

Input: 1023
Output: 10 (Binary: 1111111111)
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

int count_set_bits(int n){
    int i = 0;
    int count = 0;
    while(n != 0){
        if(n & 1){
            count++;
        }
        n >>= 1;
        i++;
    }
    return count;
}

int main(){
    int n;
    scanf("%d", &n);

    int result = count_set_bits(n);

    printf("%d\n", result);
    
    return 0;
}