/*
You are given two uint8_t numbers — a and b. You have to add them and store in 8-bit variable only. As addition may overflow (>255), you have to 

    Output the sum as it would appear in an 8-bit register (wrapped)
    Output the carry flag (1 if carry occurred, 0 otherwise)

Note: You can use only 8-bit variables. No uint16_t, no casting to larger types.

 

Example-1

Input:  a = 255, b = 1
Output: sum = 0, carry = 1


Example-2

Input:  a = 200, b = 100  
Output: sum = 44, carry = 1
*/

#include <stdio.h>
#include <stdint.h>

uint8_t sum_add(uint8_t a, uint8_t b, uint8_t * carry){
    uint8_t result = 0;
    result = a+b;
    if(a+b > 254){
        *carry = 1;
    }
    return result;
}


int main(){
    uint8_t a,b;
    scanf("%d %d", &a, &b);

    uint8_t carry = 0;

    uint8_t result = sum_add(a,b,&carry);

    printf("sum = %d, carry = %d",result, carry);

}