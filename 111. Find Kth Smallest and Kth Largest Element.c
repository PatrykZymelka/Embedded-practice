/*
You are given an array of n unsigned 8-bit integers (uint8_t) and a number k. Your task is to:

    Find the k-th smallest and k-th largest values from the array
    Output both values in a single line: smallest largest

Important Notes:

    Assume: 1 ≤ k ≤ n
    Do not use built-in sort functions
    Use a simple sorting approach (bubble/selection) and pick elements by index
     

Example-1

Input: n = 5, arr = [10 3 5 2 7], k = 2
Output: 3 7


Example-2

Input: n = 4, arr = [8 1 9 6], k = 1
Output: 1 9


Example-3

Input: n = 3, arr = [10 20 30], k = 3
Output: 30 10
*/

#include <stdio.h>
#include <stdint.h>

void sort_arr(int n, int * arr){
    int sorted = 0;
    while(sorted == 0){
        sorted = 1;
        for(int i = 0; i < n-1; i++){
            if(arr[i] > arr[i+1]){
                sorted = 0;
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

void find_k(int n, int * arr, int k){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    sort_arr(n, arr);
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("%d %d\n", arr[k-1], arr[n-k]);

}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d", &k);

    find_k(n,arr,k);
    
    return 0;
}