/*
In embedded systems, a 32-bit configuration register often contains several packed fields. 

Your task is to extract a 5-bit field located at bit positions 10 to 14 from a 32-bit register value. 

If this field’s value is less than 31, increment it by 1. Then write the updated value back to the same bit positions in the register, leaving all other bits unchanged.

Use only bitwise operations to extract, modify, and update the register.

Bit layout example (bit 0 is LSB):

Register: [31 ... 15 | 14 13 12 11 10 | 9 ... 0]
                        ↑  ↑  ↑  ↑  ↑ (target field)

 

Example-1

Input: 0x00003C00
Output: 0x00004000

(Field at bits 10–14 was 0x1E = 30 → incremented to 31)


Example-2

Input: 0x00000000
Output: 0x00000400

(Field was 0 → becomes 1)
 

Example-3

Input: 0x00007C00
Output: 0x00007C00

(Field was 31 → remains unchanged)
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

void extract_modify_field(uint32_t * reg){

    uint32_t field_val = (*reg >> 10) & 0x1F;
    if(field_val < 31){
        *reg &= ~(((1 << 5)-1)<< 10);
        *reg |= ((field_val+1) << 10);
    }


}

int main(){
    uint32_t reg;
    scanf("%u", &reg);

    void * ptr = &reg;
    binary_visualization(ptr, 32);

    extract_modify_field(&reg);

    binary_visualization(ptr, 32);

    return 0;
}