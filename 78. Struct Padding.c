/*
You are given a struct with the following fields in order:

    char a
    int b
    short c

Your task is to:

    Declare a variable of this struct
    Compute the offset (in bytes) of each field from the base address of the struct (i.e., &s)
    Print:
     
        Offset of a
        Offset of b
        Offset of c
        Total size of the struct
         

Example Output

Offset of a: 0  
Offset of b: 4  
Offset of c: 8  
Size: 12
*/

#include <stdio.h>
#include <stdint.h>

typedef struct{
    char a;
    double b;
    char c;
}Reg;

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
    Reg r;
    r.a = 'a';
    r.b = 1;
    r.c = 2;
    char * pos_a = &r.a; 
    char * pos_b = (char*)&r.b;
    char * pos_c = (char*)&r.c;
    printf("Offset of a: %d\n Offset of b: %d\n Offset of c: %d\n",pos_a - pos_a, pos_b - pos_a, pos_c - pos_a);
    
    return 0;
}