/*
You receive a 6-byte data packet from a peripheral interface (e.g., UART or I2C). The byte stream format is:
Byte Index	Field	Size
0	start	1
1	command	1
2–3	data	2
4	crc	1
5	end	1

You are given the packet as an array: uint8_t buffer[6]. Your task is to extract and print each field as integer values
 

Example-1

Input: 165 1 52 18 119 90
Output:
Start: 165
Command: 1
Data: 4660
CRC: 119
End: 90

 

Example-2

Input: 170 255 255 0 254 85
Output:
Start: 170
Command: 255
Data: 255
CRC: 254
End: 85
*/

#include <stdio.h>
#include <stdint.h>


typedef union{
    struct{
        uint8_t start;
        uint8_t command;
        uint16_t data;
        uint8_t crc;
        uint8_t end; 
    }fields;
    uint8_t bytes[6];
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
    uint8_t start, command, crc, end;
    uint16_t data;
    scanf("%hhu %hhu %hu %hhu %hhu", &start, &command,&data, &crc, &end );

    Reg r;

    r.fields.start = start;
    r.fields.command = command;
    r.fields.data = data;
    r.fields.crc = crc;
    r.fields.end = end;

    for(int i = 0; i< 6; i++){
        printf("%hu ", r.bytes[i]);
    }
    
    return 0;
}