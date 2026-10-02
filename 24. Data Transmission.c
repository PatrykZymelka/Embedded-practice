/*
You are preparing a 32-bit value to send over a communication bus. To ensure compatibility across platforms, you must convert the value into 4 bytes (big-endian order) and store them in a byte array.

 
Example 1

Input: value = 0x12345678
Output: arr[0] = 0x12, arr[1] = 0x34, arr[2] = 0x56, arr[3] = 0x78

Example 2 

Input: value = 0x01020304
Output: arr[0] = 1, arr[1] = 2, arr[2] = 3, arr[3] = 4
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

void data_trans(uint32_t reg, uint8_t * arr){
    int j = 0;
    for(int i = 3; i >=0; i--){
        arr[i] = (reg >> (j*8)) & 0xFF;
        j++;
    }

    

}

int main(){
    uint32_t reg;
    uint8_t arr[4];

    scanf("%u",&reg);

    data_trans(reg,arr);
    
    for(int i = 0; i<4;i++){
        printf("%u ", arr[i]);
    }

    return 0;
}