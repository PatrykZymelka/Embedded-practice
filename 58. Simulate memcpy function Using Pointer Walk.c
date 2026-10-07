/*
You are given two memory buffers:

    A source array of n integers
    A destination array of the same size (pre-allocated, uninitialized)

Your task:

    Implement the function simulate_memcpy() to copy all elements from the source to destination
    ✅ You must use pointer arithmetic only
    ❌ Do not use array indexing (arr[i])

 

Constraints

    1 ≤ n ≤ 100
    Data type: int
     

Example-1

Input: n = 5, source = [10, 20, 30, 40, 50]
Output: dest = 10 20 30 40 50


Example-2

Input: n = 3, source = [-5, 0, 5]
Output: dest = -5 0 5
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

void mem_cpy( int * arr, int * dest_array, int n){

    for(int i = 0; i < n; i++){
        dest_array[i] = arr[i];
    }

}


int main(){
    int n;
    scanf("%d", &n);

    int arr[100];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int dest_arr[100];
    
    return 0;
}