/*
You are given a control register represented using nested struct bitfields. The register is 8-bit wide and divided into the following layout:
Bits	Field	Description
0	enable	1 = ON, 0 = OFF
1	mode	0 = Normal, 1 = Sleep
2–3	priority	2-bit value (0–3)
4–7	reserved	Reserved (must be 0)


Your task is to:

    Simulate this register using nested struct and bitfields
    Implement a function that takes a pointer to the register and validates:
        enable must be 1
        priority must be less than or equal to 2
        reserved must be all 0s

Return 1 if valid, else return 0.

 

Example-1

Input: 0x05 → 00000101
Output: 1

(enable=1, mode=0, priority=1, reserved=0)


Example-2

Input: 0x0F → 00001111
Output: 0

(priority=3, reserved=0)


Example-3

Input: 0x95 → 10010101
Output: 0

(reserved ≠ 0)
*/

#include <stdio.h>
#include <stdint.h>

typedef union{
    struct{
        unsigned char enable: 1;
        unsigned char mode: 1;
        unsigned char priority: 2;
        unsigned char reserved:4;
    }bits;
    unsigned char reg;
}CtrlReg;

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

int fun_check(CtrlReg * r){

    if(r->bits.enable == 0){
        return 0;
    }
    else if(r->bits.priority > 2){
        return 0;
    }
    else if(r->bits.reserved != 0){
        return 0;
    }
    else{
        return 1;
    }
    

}


int main(){
    CtrlReg R;
    scanf("%hhx", &R.reg);

    int result = fun_check(&R);

    printf("%d\n", result);
    
    return 0;
}