/*
You are given two null-terminated strings.

Your task is to:

    Compare them character by character using ASCII values
    Return:
     
        0 if all characters are the same and both strings end at the same time
        If mismatched: ASCII difference of the first mismatched characters. 
        I.e. positive value if the first non-matching character in string a is greater than that in string b or negative value (vice-versa)

Do not use built-in functions like strcmp().

 

Example-1

Input: "apple" and "apple"
Output: 0


Example-2

Input: "cat" and "bat"
Output: 1 
(because 'c' - 'b' = 1)


Example-3

Input: "abc" and "abcd"
Output: -100 
(because 'a'-'a'=0, 'b'-'b'=0, 'c'-'c'=0, then '\0' - 'd' = -100)
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

int str_cmp(char * a, char * b){
    int index = 0;
    while(*(a+index) != '\0' || *(b+index) != '\0'){
        if(*(a+index) != *(b+index)){
            return (*(a+index) - *(b+index));
        }
        index++;
    }
    return 0;
}


int main(){
    char a[100], b[100];
    fgets(a, sizeof(a), stdin);
    fgets(b, sizeof(b), stdin);

    int result = str_cmp(a, b);
    
    printf("%d\n", result);
    return 0;
}