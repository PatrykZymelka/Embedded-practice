/*
Write a C program to check if the K-th bit (0-based index) of an integer N is set (1) or not (0).

Input Format

    Two integers N and K.

Output Format

    Print 1 if the K-th bit of Integer N is set (1), otherwise print 0.

 

Example

Input N= 8 &  K= 3

Here Binary value of 8 is 00001000

So output will be 1
*/

#include <stdio.h>
#include <stdint.h>

int check_bit(uint8_t reg, int k){
    if(reg & (1 << k)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    uint8_t reg;
    int k;
    scanf("%u %d",&reg,&k);
    printf("%d\n", check_bit(reg,k));
    return 0;
}