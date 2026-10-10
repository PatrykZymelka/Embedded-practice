/*
In embedded systems, floating-point values are often transmitted over UART or SPI as raw bytes. 
You are given a float value and must simulate how it would be serialized into 4 bytes.

Your task is to:

    Define a union that contains:
        A float variable
        A uint8_t[4] byte array
    Read a float from input
    Use the union to access and print the 4 individual bytes in order (LSB first)
     

Example-1

Input: 1.0
Output:
Byte 0: 0  
Byte 1: 0  
Byte 2: 128  
Byte 3: 63


Example-2

Input: -2.5
Output (example):
Byte 0: 0  
Byte 1: 0  
Byte 2: 32  
Byte 3: 192
*/

#include <stdio.h>
#include <stdint.h>

typedef union{
    float reg;
    uint8_t bytes[4];
}Uni;

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



int main(){
    float f;
    scanf("%f",&f);
    Uni u;
    u.reg = f;
    for(int i = 0; i < 4; i++){
        printf("%u ", u.bytes[i]);
    }
    
    return 0;
}