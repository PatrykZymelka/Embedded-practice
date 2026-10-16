/*
You are given a sorted array of n unsigned 8-bit integers (uint8_t) and a key to search. Your task is to:

    Perform a binary search to find the key
    Print the index of the key if found
    If not found, print -1 

Important:

    The array is guaranteed to be sorted in ascending order
    Use only loop-based (iterative) binary search — no recursion


Example-1

Input: n = 6, arr = [5 10 15 20 25 30], key = 20
Output: 3


Example-2

Input: n = 5, arr = [2 4 6 8 10], key = 1
Output: -1


Example-3

Input: n = 4, arr = [100 150 200 250], key = 250
Output: 3


*/

#include <stdio.h>
#include <stdint.h>

int binary_search(uint8_t * arr, uint8_t n, uint8_t key){

    int max, min, mid;
    min = 0;
    max = n-1;
    while(min <= max){
        mid = min+(max-min)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            max = mid-1;
        }
        else{
            min = mid+1;
        }
    }
    return -1;

}

int main(){
    uint8_t n;
    scanf("%d", &n);
    uint8_t arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    uint8_t key;
    scanf("%d", &key);
    int result = binary_search(arr, n, key);
    printf("%d\n",result);
    return 0;
}