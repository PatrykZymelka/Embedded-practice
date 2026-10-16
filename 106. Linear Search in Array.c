/*
You are given an array of n unsigned 8-bit integers (uint8_t) and a key. Your task is to:

    Search for the key
    Print the index of its first occurrence
    If not found, print -1

Do not use standard library functions. Use only loop and index logic.

Example-1

Input: n = 5, arr = [10 20 30 40 50], key = 30
Output: 2


Example-2

Input: n = 4, arr = [5 8 12 9], key = 7
Output: -1


Example-3

Input: n = 6, arr = [1 1 2 3 1 4], key = 1
Output: 0
*/

#include <stdio.h>
#include <stdint.h>

int linear_search(int n, int * arr, int key){

    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;

}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int key;
    scanf("%d", &key);

    int result = linear_search(n,arr,key);
    
    printf("%d", result);
    return 0;
}