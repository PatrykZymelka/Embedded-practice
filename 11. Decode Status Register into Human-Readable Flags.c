/*
In embedded systems, status registers often represent multiple flags using each bit. You are given an 8-bit status register. Each bit corresponds to a different condition.

Bit-to-Flag Mapping
Bit	Meaning
0	Power On
1	Error
2	Tx Ready
3	Rx Ready
4	Overheat
5	Undervoltage
6	Timeout
7	Reserved

You must write a function that:

    Accepts a uint8_t status_reg
    Decodes which flags are set (bits = 1)
    Prints only the enabled flag names, one per line, in the order of bits from LSB to MSB (0 to 7)
     

Example-1

Input: 

13

Output:

Power On
Tx Ready
Rx Ready

Example-2

Input: 

48

Output:

Overheat
Undervoltage

Example-3

Input: 

255

Output:

Power On
Error
Tx Ready
Rx Ready
Overheat
Undervoltage
Timeout
Reserved
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

void decode_status(uint8_t reg){
    char arr[8][20] = {"Power On", "Error", "Tx Ready", "Rx Ready", "Overheat", "Undervoltage", "Timeout", "Reserved"};
    int i = 0;
    while(i < 8){
        if((reg >> i) & 1){
            printf("%s\n", arr[i]);
        }
        i++;
    }  
}

int main(){
    uint8_t reg = 0;
    scanf("%u", &reg);
    void * ptr = &reg;
    binary_visualization(ptr, 8);

    decode_status(reg);

    return 0;


}