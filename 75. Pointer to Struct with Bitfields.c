/*
You are given a pointer to a UART_ControlRegister struct representing a 32-bit hardware register.
The struct has the following bitfields:

struct UART_ControlRegister {
    unsigned int baudrate : 4;   // Bits 0-3
    unsigned int tx_enable : 1;  // Bit 4
    unsigned int rx_enable : 1;  // Bit 5
    unsigned int tx_irq_en : 1;  // Bit 6
    unsigned int rx_irq_en : 1;  // Bit 7
    unsigned int parity_en : 1;  // Bit 8
    unsigned int stop_bits : 1;  // Bit 9
    unsigned int reserved : 22;  // Bits 10-31
};

    Your task:
    Write a function that receives a pointer to this struct.
    Set the UART configuration:
        Baud rate = 9
        TX & RX enable = 1
        TX IRQ = 1, RX IRQ = 0
        Parity = 1
        Stop bit = 0
    Print each field’s value after configuration.

     

Example

Output:
baudrate = 9
tx_enable = 1
rx_enable = 1
tx_irq_en = 1
rx_irq_en = 0
parity_en = 1
stop_bits = 0
*/

#include <stdio.h>
#include <stdint.h>

struct UART_ControlRegister {
    unsigned int baudrate : 4;   // Bits 0-3
    unsigned int tx_enable : 1;  // Bit 4
    unsigned int rx_enable : 1;  // Bit 5
    unsigned int tx_irq_en : 1;  // Bit 6
    unsigned int rx_irq_en : 1;  // Bit 7
    unsigned int parity_en : 1;  // Bit 8
    unsigned int stop_bits : 1;  // Bit 9
    unsigned int reserved : 22;  // Bits 10-31
};

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

void set_uart(struct UART_ControlRegister * U){
    U->baudrate = 9;
    U->tx_enable = 1;
    U->rx_enable = 1;
    U->tx_irq_en = 1;
    U->rx_irq_en = 0;
    U->parity_en = 1;
    U->stop_bits = 0;
}

int main(){
    struct UART_ControlRegister U;
    set_uart(&U);
    return 0;
}