/*
In C, the strcpy() function copies a null-terminated string from source to destination.

Your task is to implement a custom version of strcpy() that copies one string into another without using built-in functions.

You will be given:

    A source string src
    A destination buffer dest[101] (you must copy into it)

Ensure the destination is null-terminated, just like standard strcpy.

 

Example-1

Input: "firmware"
Output: firmware


Example-2

Input: "abc 123"
Output: abc 123


Example-3

Input: ""
Output: ``
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

void cust_strcpy(char * dest, char * src){
    int index = 0;
    while(*(src+index) != '\0'){
        *(dest+index) = *(src+index); 
        index++;
    }
    *(dest+index) = '\0';

}

int main(){
    char src[100];
    char dest[100];
    fgets(src, sizeof(src), stdin);

    cust_strcpy(dest, src);
    
    printf("%s\n", dest);
    return 0;
}