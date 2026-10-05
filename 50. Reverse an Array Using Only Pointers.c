/*
You are given an array of integers and its size n.
Using only pointer arithmetic:

    Reverse the array elements in-place.
    Print the reversed array.

❌ Do not use array indexing like arr[I].
✅ Only use pointer movements and dereferencing.

 

Example-1

Input: n = 5, arr = [1 2 3 4 5]
Output: 5 4 3 2 1


Example-2

Input: n = 4, arr = [10 20 30 40]
Output: 40 30 20 10


Example-3

Input: n = 3, arr = [7 8 9]
Output: 9 8 7
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

void reverse_array(int * arr, int n){

    for(int i = 0; i < n/2; i++){

        arr[i] = arr[i] ^ arr[n-1-i];
        arr[n-1-i] = arr[i] ^ arr[n-1-i];
        arr[i] = arr[i] ^ arr[n-1-i];

    }

}

int main(){
    int n;
    scanf("%d", &n);

    int arr[100];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");

    reverse_array(arr, n);
    
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}