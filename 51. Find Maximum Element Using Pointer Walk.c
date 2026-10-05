/*
You are given an array of integers and its size n.
Using only pointer arithmetic:

    Traverse the array
    Find and print the maximum element in the array.

❌ Do not use array indexing like arr[I].
✅ Only use pointer movements and dereferencing.
 

Example-1

Input: n = 5, arr = [10 25 5 30 15]
Output: 30


Example-2

Input: n = 4, arr = [1 1 1 1]
Output: 1


Example-3

Input: n = 3, arr = [-5 -2 -9]
Output: -2
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

int find_max(int * arr, int n){

    int max = (*arr);
    
    for(int i = 0; i < n; i++){
        if(*(arr+i) > max){
            max = *(arr+i);
        }
    }
    return max;

}

int main(){
    int arr[100];
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int result = find_max(arr, n);

    printf("%d\n", result);
    
    return 0;
}