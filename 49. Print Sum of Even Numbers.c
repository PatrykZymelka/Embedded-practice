/*
You are given an array of integers and its size. Using only pointer arithmetic:

    Traverse the array
    Find the sum of all even numbers
    Print the sum 

❌ Do not use arr[ i ] indexing.
✅ Use only pointer movement and dereferencing.
 

Example-1

Input: n = 5, arr = [10 21 32 43 50]
Output: Sum = 92


Example-2

Input: n = 4, arr = [11 13 15 17]
Output: Sum = 0


Example-3

Input: n = 6, arr = [2 4 6 8 10 12]
Output: Sum = 42
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

int even_sum(int * reg, int n){
    int result = 0;
    for(int i = 0; i < n; i++){
        if(*(reg+i) %2 == 0){
            result += *(reg+i);
        }
    }
    return result;


}

int main(){
    
    int n;
    scanf("%d", &n);

    int reg[100];
    for(int i = 0; i < n ; i++){
        scanf("%d", &reg[i]);
    }

    int result = even_sum(reg, n);
    printf("%d\n", result);
    
    return 0;
}