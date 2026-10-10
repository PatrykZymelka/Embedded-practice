/*
Many embedded microcontrollers store ADC results in a packed format where a 12-bit ADC value and channel number are stored together in a 16-bit register.

You are given a 16-bit ADC register where:

    Bits 0–11 represent the ADC result (0–4095)
    Bits 12–15 represent the ADC channel (0–15)

Your task is to:

    Define a union that overlays:
        A raw 16-bit uint16_t adc_reg
        A struct with:
            adc_value (12 bits)
            channel (4 bits)
    Read adc_reg from input
    Extract and print:
        Channel number
        ADC result (0–4095)
         

Example-1

Input: 0xC3F5
Output:
Channel: 12  
ADC Value: 1013

 

Example-2

Input: 0x10FF
Output:
Channel: 1  
ADC Value: 255
*/

#include <stdio.h>
#include <stdint.h>

typedef union{
    uint16_t reg;
    struct{
        uint16_t adc_result: 12;
        uint16_t adc_channel: 4;
    };
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
    Uni u;
    uint16_t reg;
    scanf("%hx", &reg);
    u.reg = reg;

    printf("ADC value: %d\n", u.adc_result);
    printf("ADC channel: %d\n",u.adc_channel);
    
    return 0;
}