/*
You are given a null-terminated string containing lowercase and uppercase letters, digits, symbols, or spaces.

Your task is to:

    Remove all duplicate characters from the string
    Keep only the first occurrence of each character

The order of characters must be preserved.
 

Example-1

Input: "programming"
Output: progamin


Example-2

Input: "aabbcc"
Output: abc


Example-3

Input: "C language"
Output: C langue
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

void remove_duplicates(char * str){
    uint8_t hash_table[128] = {0};
    int read = 0;
    int write = 0;
    while(*(str+read) != '\0'){
        uint8_t val = *(str+read);
        //Value has no duplicates
        if(hash_table[val] == 0){
            hash_table[val] = 1;
            *(str+write) = *(str+read);
            write++;
        }
        //Value has a duplicate
        read++;
    }
    *(str+write) = '\0';


}

int main(){
    char str[100];

    fgets(str, sizeof(str), stdin);

    remove_duplicates(str);

    printf("%s",str);
    
    return 0;
}