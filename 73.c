/*

*/

#include <stdio.h>
#include <stdint.h>

typedef union {
   struct {
    
        uint32_t payload1;
        uint8_t ex1;
       uint8_t header;
       uint32_t payload;
   } fields;
   uint8_t raw[5];
} Packet;

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
    Packet p;
    printf("%d", sizeof(p));
    
    return 0;
}