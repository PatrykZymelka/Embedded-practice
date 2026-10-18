/*
You are given an array of n unsigned 8-bit integers (uint8_t). Your task is to:

    Find the top 3 largest values from the array
    Print the values in descending order
    If n < 3, print all available values in descending order

Do not use any built-in sort functions. Use simple logic.


Example-1

Input: n = 6, arr = [10 90 20 80 70 30]
Output: 90 80 70


Example-2

Input: n = 2, arr = [5 200]
Output: 200 5


Example-3

Input: n = 3, arr = [1 2 3]
Output: 3 2 1

*/

#include <stdio.h>
#include <stdint.h>

void sort_arr(uint8_t n, uint8_t * arr){
    int count = 0;
    while(count == 0){
        count = 1;
        for(int i = 0; i < n-1; i++){
            if(arr[i] < arr[i+1]){
                count = 0;
                arr[i] = arr[i] ^ arr[i+1];
                arr[i+1] = arr[i] ^ arr[i+1];
                arr[i] = arr[i] ^ arr[i+1];
            }
        }
    }
}

void print_3_largest(uint8_t n, uint8_t * arr){
    sort_arr(n, arr);
    if(n > 3){
        n = 3;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    uint8_t n;
    scanf("%hhu",&n);
    uint8_t arr[n];
    for(int i = 0; i < n; i++){
        scanf("%hhu", &arr[i]);
    }

    print_3_largest(n,arr);
    
    return 0;
}