/*
You are given a comma-separated string of integers (e.g., "10,20,30"). Each number is in the range 0–255.

Your task is to parse the string and extract all numbers into an array of integers.

    Use only basic string logic (do not use strtok() or standard tokenizing functions)
    Stop at the null terminator ('\0')
    Store results into an uint8_t[] array and print them
     

Example-1

Input: "10,20,30"
Output: 10 20 30

 

Example-2

Input: "5"
Output: 5

 

Example-3

Input: "1,2,3,4,5"
Output: 1 2 3 4 5
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

void parse_comma(char * src, int * arr, int * count){
    int index = 0;
    while(*(src+index) != '\0'){
        if(*(src+index) != ',' && *(src+index) != '\n'){
            arr[*count] = arr[*count] * 10 + (*(src+index) - '0');
        }
        else{
            (*count)++;
        }
        index++;
    }
}

int main(){
    char src[100];
    int arr[100] = {0};

    fgets(src, sizeof(src), stdin);

    int count = 0;
    parse_comma(src,arr, &count);

    for(int i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}