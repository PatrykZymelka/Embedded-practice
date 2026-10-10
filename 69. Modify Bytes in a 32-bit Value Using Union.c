/*
You are given a 32-bit integer.

You must:

    Use a union to access and modify its individual bytes
    Modify the 2nd and 3rd bytes (i.e., bytes[1] and bytes[2]) with new values
    Reconstruct and print the modified 32-bit value

Only use union-based access. Do not use bitwise operations or shifts.


Example-1

Input: 
value = 305419896 (0x12345678)
new_b1 = 0xAA, new_b2 = 0xBB
Output: 314288760

(0x12BBAA78 → bytes = [0x78, 0xAA, 0xBB, 0x12])


Example-2

Input: 
value = 1
new_b1 = 255, new_b2 = 255
Output: 16776961

(0x00FFFF01)


Example-3

Input: 
value = 0
new_b1 = 1, new_b2 = 2
Output: 131328

(0x00020100)
*/

#include <stdio.h>
#include <stdint.h>

typedef union{

    uint32_t reg;
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

void change_bytes(Uni * u, uint8_t b1, uint8_t b2){
    u->bytes[1] = b1;
    u->bytes[2] = b2;
}

int main(){
    uint32_t reg;
    scanf("%d",&reg);
    
    Uni U;
    U.reg = reg;

    

    uint8_t b1, b2;
    scanf("%d %d", &b1, &b2);
    
    printf("Before : %d\n", U.reg);
    
    change_bytes(&U, b1, b2);

    printf("After: %d\n", U.reg);
    
    return 0;
}