/*
Write a function that receives two void pointers, each pointing to an integer. Return sum of the two integer.

Note: Function arguments are passed as void * and can’t be changed.


Example-1

Input: a = 10, b = 20
Output: 30


Example-2

Input: a = -5, b = 15
Output: 10


Example-3

Input: a = 100, b = 200
Output: 300
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

int void_sum(void * ptr1, void * ptr2){

    return *(int*)ptr1 + *(int*)ptr2;
}

int main(){
    int a,b;
    void * ptr1 = &a;
    void * ptr2 = &b;

    scanf("%d %d",&a, &b );


    int result = void_sum(ptr1, ptr2);

    printf("%d\n", result);
    return 0;
}