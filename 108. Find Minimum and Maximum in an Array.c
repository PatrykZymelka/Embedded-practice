/*
You are given an array of n unsigned 8-bit integers (uint8_t). Your task is to:

    Find the minimum and maximum values in the array
    Print both values in a single line: first the minimum, then the maximum
     

Example-1

Input: n = 5, arr = [10 20 5 30 15]
Output: 5 30

 

Example-2

Input: n = 3, arr = [255 0 128]
Output: 0 255

 

Example-3

Input: n = 1, arr = [42]
Output: 42 42
*/

#include <stdio.h>
#include <stdint.h>

void min_max(uint8_t arr[], uint8_t n){

    uint8_t max = arr[0];
    uint8_t min = max;
    for(int i = 0; i < n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
        if(min > arr[i]){
            min = arr[i];
        }
    }
    printf("Minimum = %d\nMaximium = %d\n",min,max);

}

int main(){
    uint8_t n;
    scanf("%d", &n);
    uint8_t arr[100];
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    min_max(arr,n);
    
    return 0;
}