/*
You are given a null-terminated string of up to 100 characters. Your task is to:

    Convert all uppercase letters (A–Z) to lowercase (a–z)
    Leave all other characters unchanged (lowercase, digits, symbols, spaces)
    Perform the conversion in-place, using only basic character logic
    Do not use standard functions like tolower()
     

Example-1

Input: "Hello Embedded"
Output: hello embedded

 

Example-2

Input: "C99 IS POWERFUL!"
Output: c99 is powerful!

 

Example-3

Input: "test123"
Output: test123
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

void to_lower(char * s){
    int i = 0;
    while(*(s+i) != '\0'){
        if(*(s+i) >= 'A' && *(s+i) <= 'Z'){
            *(s+i) += ('a' - 'A');
        }
        i++;
    }
}

int main(){
    char source[100];
    fgets(source, sizeof(source), stdin);

    to_lower(source);

    printf("%s\n", source);
    
    return 0;
}