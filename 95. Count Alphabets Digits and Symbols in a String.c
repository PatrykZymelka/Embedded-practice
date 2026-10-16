/*
You are given a null-terminated string containing alphabets, digits, symbols, and spaces. Your task is to:

    Count the number of:
        Alphabets (A–Z, a–z)
        Digits (0–9)
        Other symbols (anything that is not alphabet, digit, or space)

Avoid using standard library functions like isalpha(), isdigit().

 

Example-1

Input: "C99_Firmware!"
Output:
Alphabets = 9  
Digits = 2  
Symbols = 2

 

Example-2

Input: "123@hello#"
Output:
Alphabets = 5  
Digits = 3  
Symbols = 2
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

void count(char * source, int * a, int * d, int * s){
    int i = 0;
    while(*(source+i) != '\0'){
        if(*(source+i) >= '0' && *(source+i) <='9'){
            (*d)++;
        }
        else if((*(source+i) >= 'a' && *(source+i) <= 'z') || (*(source+i) >= 'A' && *(source+i) <= 'Z') ){
            (*a)++;
        }
        else if(*(source+i) == ' ' || *(source+i) == '\n'){}
        else{
            (*s)++;
        }
        i++;
    }

}

int main(){
    int a = 0;
    int d = 0;
    int s = 0;
    char source[100];
    fgets(source, sizeof(source), stdin);

    count(source, &a, &d, &s);
    
    printf("alphabet = %d\ndigits = %d\nspecial = %d\n", a, d, s);
    return 0;
}