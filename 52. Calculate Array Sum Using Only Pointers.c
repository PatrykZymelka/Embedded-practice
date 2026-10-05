/*
You are given an array of integers and its size n.
Using only pointer arithmetic:

    Traverse the array
    Find and print the sum of all elements.

❌ Do not use array indexing like arr[I].
✅ Only use pointer movements and dereferencing.

 

Example-1

Input: n = 5, arr = [1 2 3 4 5]
Output: 15


Example-2

Input: n = 4, arr = [10 20 30 40]
Output: 100


Example-3

Input: n = 3, arr = [-5 5 10]
Output: 10
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


int array_sum(int * arr, int n){

    int sum = 0;

    for(int i = 0; i < n; i++){

        sum += *(arr+i);

    }
    
    return sum;

}

int main(){
    int arr[100];
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int result = array_sum(arr, n);

    printf("%d\n", result);
    
    return 0;
}