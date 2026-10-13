/*
You are given a ConfigRegister struct that simulates a 16-bit configuration register.
Each bit in the register has a specific meaning:
Bit Position	Meaning
0	Enable (1 = ON)
1	Mode (0 = Normal, 1 = Safe)
2–3	Priority (00 = Low, 01 = Medium, 10 = High, 11 = Invalid)
4–15	Reserved (must be 0)

Your task is to validate the register:

    Return 1 if:
        Bit 0 is set (Enable ON)
        Bits 2–3 contain a valid priority (not 11)
        All bits 4–15 are 0
    Return 0 otherwise

Use pointer logic (-> or (*ptr).field) to access the data.
 

Example-1

Input: reg = 0x0005 (binary: 0000000000000101)
Output: 1

(Enable = 1, Mode = 0, Priority = 01 → Valid)


Example-2

Input: reg = 0x000B (binary: 0000000000001011)
Output: 1


Example-3

Input: reg = 0x0015 (binary: 0000000000010101)
Output: 0

(Bit 4 is set → Reserved violation)
*/

#include <stdio.h>
#include <stdint.h>

typedef struct{
    uint16_t reg;
}Register;

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

int validate(Register * r){
    uint16_t val = ((r->reg) >> 2) & 0x03;
    if(((r->reg) & 1) == 0){
        return 0;
    }
    else if(val == 0x03){
        return 0;
    }
    else if(((r->reg) & 0xFFF0) != 0){
        return 0;
    }

    return 1;
}


int main(){
    uint16_t input;
    scanf("%x",&input);
    Register r;
    r.reg = input;

    validate(&r);


    
    return 0;
}