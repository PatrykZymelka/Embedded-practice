/*
In firmware development, you might need to convert numbers to binary or hexadecimal strings manually — for instance, sending over UART or displaying on an LCD —
 without using standard library functions like itoa().

Your task is to:

    Read an unsigned integer num and a base (2 or 16)
    Print the number in the given base as a string
    You must not use any standard string conversion like itoa() or sprintf()
    Use only loops and arithmetic

 

Example-1

Input: num = 10, base = 2
Output: 1010


Example-2

Input: num = 255, base = 16
Output: FF


Example-3

Input: num = 0, base = 2
Output: 0
*/

#include <stdio.h>
#include <stdint.h>

void decimal_to_binary(int n){
    int result = 0;
    for(int i = 7; i >= 0; i--){
        if(n & (1<<i)){
            result = result * 10 + 1; 
        }
        else{
            result = result * 10;
        }
    }
    printf("%d\n", result);
}

void decimal_to_hex(int n){
    printf("%x",n);
}

int main(){
    int n;
    scanf("%d", &n);
    int base;
    scanf("%d", &base);
    if(base == 2){
        decimal_to_binary(n);
    }
    else if(base == 16){
        decimal_to_hex(n);
    }
    
    return 0;
}