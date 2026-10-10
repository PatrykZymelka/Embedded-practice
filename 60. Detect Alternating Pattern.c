/*
You are given a memory block as an integer array of size n. 

Your task is to check if a segment of size k starting from the beginning of the array follows an alternating pattern — e.g., 1 0 1 0 ... or 0 1 0 1 ....

Return:

    1 if the segment follows an alternating pattern
    0 if not

You must use pointer arithmetic only, not array indexing.

 

Example-1

Input: n = 6, k = 6, mem = [1, 0, 1, 0, 1, 0]
Output: 1


Example-2

Input: n = 6, k = 6, mem = [0, 1, 0, 1, 0, 1]
Output: 1


Example-3

Input: n = 6, k = 6, mem = [1, 1, 0, 1, 0, 1]
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

int pattern(int * arr, int n){

    for(int i = 0; i < n-1; i++){
        if(*(arr+i) == *(arr+i+1)){
            return 0;
        }
    }
    return 1;

}

int main(){

    int n;
    scanf("%d", &n);

    int arr[100];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int result = pattern(arr, n);
    printf("%d\n", result);

    return 0;
}