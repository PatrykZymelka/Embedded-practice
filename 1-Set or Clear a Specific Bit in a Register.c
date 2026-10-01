/*
Write a C program to set or clear a specific bit in an 8-bit register based on user input.

    The user provides an 8-bit integer (register value), a bit position (0-7), and a mode (0 for clear, 1 for set).
    Your task is to modify the register value accordingly and print the updated value.

Input Format

    An 8-bit integer (0-255) representing the register value.
    An integer (0-7) representing the bit position.
    An integer (0 or 1) representing the operation (1 to set, 0 to clear the bit).

Output Format

    The modified register value after setting/clearing the bit.

Example 1 (Setting Bit 3)

Input

10 3 1

Output

10

Explanation:

    10 in binary = 00001010
    Setting bit 3 → 00001010 (decimal 10)
*/
#include <stdio.h>
#include <stdint.h>

void set_clear_bit(uint8_t * reg, int pos, int operation){
    if(operation == 0){
        *reg &= ~(1 << pos);
    }
    else if(operation == 1){
        *reg |= (1 << pos);
    }
    else{
        printf("Invalid input, operaion value needs to be equal to | 1 - for set | 0 for clear\n");
    }

}

int main(){
    uint8_t reg;
    int pos;
    int operation;

    scanf("%u %d %d",&reg,&pos,&operation);
    set_clear_bit(&reg, pos, operation);
    printf("%u\n",reg);


}