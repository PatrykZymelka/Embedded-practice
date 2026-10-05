/*
You are given two pointers, each pointing to different integer variables.

Task:

    Write a function that swaps the pointers themselves (not the values).
    After swapping, each pointer should now point to the other’s original variable.

 You must use double pointers (int **p1, int **p2) to swap addresses.
 

Example-1

Input: a = 10, b = 20
Output: a points to 20, b points to 10


Example-2

Input: a = 5, b = 15
Output: a points to 15, b points to 5
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

void swap_ptr(int ** ptr1, int ** ptr2){
    int * temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;


}

int main(){
    int n1 = 51;
    int n2 = 22;

    int * ptr1 = &n1;
    int * ptr2 = &n2;

    printf("ptr1 = %d, ptr2 = %d", *ptr1, *ptr2);

    swap_ptr(&ptr1, &ptr2);

    printf("ptr1 = %d, ptr2 = %d", *ptr1, *ptr2);
    
    return 0;
}