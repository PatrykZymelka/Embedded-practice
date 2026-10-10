/*
You are implementing UART data transmission logic. A control register configures parity settings for data framing. 
The control register is defined as an 8-bit register:
 

typedef struct {
    uint8_t parity_enable : 1;   // 0 = Disabled, 1 = Enabled
    uint8_t parity_type   : 1;   // 0 = Even parity, 1 = Odd parity
    uint8_t reserved      : 6;   // Reserved bits
} UART_Control;

 

You’re given a 7-bit data (0–127). Your task is to create an 8-bit UART frame using the control register:

    If parity is disabled, the MSB (bit 7) is 0, and the remaining 7 bits are data.
    If parity is enabled:
        Count the number of 1s in the 7-bit data.
        Add a parity bit at the MSB (bit 7):
            Even parity ➝ parity bit = 0 if 1s are even, 1 if odd.
            Odd parity  ➝ parity bit = 1 if 1s are even, 0 if odd.

 

Parity in Simple Terms

Parity is an error-detection bit added to the data:

    Even parity → total number of 1s (including parity) must be even
    (e.g., data = 1011 → has 3 ones → parity = 1 → 10001011)
     
    Odd parity  → total number of 1s (including parity) must be odd
    (e.g., data = 1010 → has 2 ones → parity = 1 → 10001010)

     

Example-1

Input: data = 85, parity_enable = 1, parity_type = 0
Output: frame = 0x55


Example-2

Input: data = 3, parity_enable = 1, parity_type = 1
Output: frame = 0x83


Example-3

Input: data = 25, parity_enable = 0, parity_type = 0
Output: frame = 0x19
*/

#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t parity_enable : 1;   // 0 = Disabled, 1 = Enabled
    uint8_t parity_type   : 1;   // 0 = Even parity, 1 = Odd parity
    uint8_t reserved      : 6;   // Reserved bits
} UART_Control;


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

void UART_data_frame(UART_Control * U, uint8_t * data,uint8_t par_en, uint8_t par_type){
    
    U->parity_type = par_type;
    if(par_en == 0){
        U->parity_enable = 0;
    }
    else{
        int par = 0;
        for(int i = 0; i < 7; i++){
            if((*data)&(1<<i)){
                par++;
            }
        }
        if(par%2==0){
            if(U->parity_type==0){
                U->parity_enable=0;
            }
            else{
                U->parity_enable=1;
            }
        }
        else{
            if(U->parity_type==0){
                U->parity_enable=1;
            }
            else{
                U->parity_enable=0;
            }
        }
        
    }
    *data &= ~(1<<7);
    if(U->parity_enable){
        *data |= (1 << 7);
    }

}


int main(){
    UART_Control U;
    uint8_t data, par_en, par_type;
    scanf("%u %u %u", &data, &par_en, &par_type);

    UART_data_frame(&U, &data, par_en, par_type);
    printf("%x\n", data);
    
    return 0;
}