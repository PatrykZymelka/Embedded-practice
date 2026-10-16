/*
You are given a null-terminated string (maximum 100 characters). 
Your task is to reverse the string in-place without using any additional array or library functions like strrev().

You must swap characters from both ends until the string is reversed. The null-terminator must remain at the end.

Example-1

Input: "firmware"
Output: erawmrif


Example-2

Input: "abc 123"
Output: 321 cba


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

int get_str_len(char * str){
    int i = 0;
    while(*(str+i) != '\0'){
        i++;
    }
    return i;
}

void reverse_str(char * src){
    int n = get_str_len(src);
    for(int i = 0; i < n/2; i++){
        char temp = *(src+i);
        *(src+i) = *(src+n-1-i);
        *(src+n-1-i) = temp;
    }


}

int main(){
    char src[100];
    printf("Input: ");
    scanf("%s", &src);

    reverse_str(src);

    printf("Output : %s\n", src);

    return 0;
}