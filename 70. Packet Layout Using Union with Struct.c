/*
You’re implementing a communication packet for transmission. Each packet is 6 bytes structured as follows:
Field	Size (bytes)
Start Byte	1
Command	1
Data (2B)	2
CRC	1
End Byte	1

 

Your task is to:

    Define a union that overlays:
        a struct view of these fields, and
        a uint8_t[6] array view
    Accept values for start, command, data (16-bit), CRC, and end
    Fill the packet struct
    Print the raw 6-byte array using the byte array view
     

Example-1

Input: start = 0xA5, cmd = 0x01, data = 0x1234, crc = 0x77, end = 0x5A
Output: 165 1 52 18 119 90

 

Example-2

Input: start = 0xAA, cmd = 0xFF, data = 0x00FF, crc = 0xFE, end = 0x55
Output: 170 255 255 0 254 85
*/

#include <stdio.h>
#include <stdint.h>

typedef union{

    uint8_t bytes[6];
    struct{
        uint8_t start;
        uint8_t command;
        uint16_t data;
        uint8_t crc;
        uint8_t end;
    }fields;
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

void input_values(Uni * u, uint8_t start, uint8_t command, uint8_t crc, uint8_t end, uint16_t data){

    u->fields.start = start;
    u->fields.command = command;
    u->fields.data = data;
    u->fields.crc = crc;
    u->fields.end = end;
    

}

void print_vales(Uni u){
    for(int i = 0; i < 6; i++){
        printf("%u ", u.bytes[i]);
    }
}

int main(){
    uint8_t start, command, crc, end;
    uint16_t data;
    scanf("%hhu %hhu %hu %hhu %hhu", &start, &command, &data, &crc, &end);
    Uni u;
    input_values(&u, start, command, crc, end, data);
    print_vales(u);

    
    return 0;
}