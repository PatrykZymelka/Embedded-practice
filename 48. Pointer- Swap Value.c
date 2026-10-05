/*
You are given two integers a and b. Write a function that swaps their values using pointers. 
You must pass the addresses of both variables to the function. After swapping, print their updated values in main().
 

Example-1

Input: a = 10, b = 20
Output: a = 20, b = 10


Example-2

Input: a = -5, b = 15
Output: a = 15, b = -5
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

void swap_values(int * a, int * b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;

}

int main(){
    int a,b;
    scanf("%d %d",&a,&b);

    printf("a = %d, b = %d\n", a, b);

    swap_values(&a,&b);
    
    printf("a = %d, b = %d\n", a, b);

    return 0;
}