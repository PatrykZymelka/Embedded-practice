/*
You are working with a 32-bit UART control register. The baud rate is controlled by 4 bits located at position 8 (i.e., bits 8 to 11). 

Write a function to update the baud rate field with a new 4-bit value. All other bits in the register must remain unchanged.


Example 1

Input: reg = 0b0000 0000 0000 0000 0000 0000 0000 0000, baud = 0b1010  
Output: 0b0000 0000 0000 0000 0000 1010 0000 0000

Example 2

Input: reg = 0b1111 1111 1111 1111 1111 1111 1111 1111, baud = 0b0000  
Output: 0b1111 1111 1111 1111 1111 0000 1111 1111
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

void update_baud_rate(uint32_t * reg, uint32_t val){
    
    *reg &= ~(0xF << 8);
    *reg |= (val << 8);

}


int main(){
    uint32_t reg;
    uint32_t val;
    scanf("%u %u", &reg, &val);

    void * ptr = &reg;
    binary_visualization(ptr, 32);

    update_baud_rate(&reg,val);

    binary_visualization(ptr, 32);


    return 0;
}