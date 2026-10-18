/*
You are given an array of n unsigned 8-bit integers (uint8_t). Your task is to:

    Sort the array in ascending order
    Print the sorted array as space-separated values 

Do not use any standard library sort functions.

Use only loop and comparison logic (firmware-safe implementation).


Example-1

Input: n = 5, arr = [10 3 5 2 7]
Output: 2 3 5 7 10


Example-2

Input: n = 3, arr = [255 0 128]
Output: 0 128 255


Example-3

Input: n = 1, arr = [42]
Output: 42
*/

#include <stdio.h>
#include <stdint.h>

void sort_ascending_order(uint8_t * arr, uint8_t n){
    int done = 0;
    while(done == 0){
        done = 1;
        for(int i = 0; i < n-1; i++){
            if(arr[i] > arr[i+1]){
                done = 0;
                uint8_t temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}


int main(){

    uint8_t n;
    scanf("%d", &n);
    uint8_t arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]); 
    }

    sort_ascending_order(arr, n);
    return 0;
}