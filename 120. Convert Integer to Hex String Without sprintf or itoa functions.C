/*
In embedded systems, you may need to transmit an integer value as a hexadecimal string over UART, 
display, or logs — but without using heavy standard functions like sprintf() or itoa().

Your task is to:

    Read an unsigned 16-bit integer num
    Print its hexadecimal string representation in uppercase
    Do not use any built-in conversion functions like itoa(), sprintf(), etc.


Example-1

Input: 255
Output: FF


Example-2

Input: 4095
Output: FFF


Example-3

Input: 0
Output: 0


Example-4

Input: 4660
Output: 1234
*/

#include <stdio.h>
#include <stdint.h>

void reverse_arr(char * output){
    int i = 0;
    while(output[i] != '\0'){
        i++;
    }
    for(int j = 0; j <i/2;j++){
        output[j] = output[j] ^ output[i-1-j];
        output[i-1-j] = output[j] ^ output[i-1-j];
        output[j] = output[j] ^ output[i-1-j];
    }
}

void dec_to_hex(uint16_t input, char * output){

    if(input == 0){
        output[0] = '0';
        output[1] = '\0';
        return;
    }
    int i = 0;
    while(input != 0){
        int val = 0;
        val = (input & 0xF);
        if(val <= 9){
            output[i] = val + '0';
        }
        else{
            output[i] = val - 10 + 'A';
        }
        input = input >> 4;
        i++;
    }
    reverse_arr(output);
    output[i] = '\0';

}

int main(){
    uint16_t input;
    scanf("%hu", &input);
    char output[4];
    dec_to_hex(input, output);
    
    int i = 0;
    while(output[i] != '\0'){
        printf("%c", output[i]);
        i++;
    }

}