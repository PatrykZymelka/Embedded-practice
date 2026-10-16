/*
ou are given a null-terminated input string. Your task is to:

    Print "NUMERIC" if the string contains only digits (0–9)
    Print "ALPHABETIC" if the string contains only letters (A–Z, a–z)
    Otherwise, print "MIXED" if it contains anything else (symbols, mix of digits and letters)

Do not use standard library functions like isdigit() or isalpha(). Use only ASCII value checks.

Example-1

Input: "123456"
Output: NUMERIC


Example-2

Input: "firmwareC"
Output: ALPHABETIC


Example-3

Input: "C99"
Output: MIXED


Example-4

Input: "Hello!"
Output: MIXED


Example-5

Input: ""
Output: MIXED (empty string is considered mixed)
*/

#include <stdio.h>
#include <stdint.h>

void str_type(char * str){

    int i = 0;
    int numeric = 0;
    int alpha = 0;
    int mixed = 0;
    while(str[i] != '\0'){
        if(str[i] >= '0' && str[i] <= '9'){
            numeric = 1;
        }
        else if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            alpha = 1;
        }
        else{
            printf("MIXED\n");
            return;
        }
        i++;
    }
    if(numeric == 1 && alpha == 0){
        printf("NUMERIC");
    }
    else if(numeric == 0 && alpha == 1){
        printf("ALPHABETIC");
    }
    else{
        printf("MIXED\n");
    }

}

int main(){
    char str[100];
    fgets(str, sizeof(str), stdin);

    str_type(str);
    
    return 0;
}