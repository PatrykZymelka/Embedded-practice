/*
You are given a null-terminated string that may contain:

    An optional sign (+ or -) at the beginning
    A numeric part made of digits
    Other non-digit characters (e.g., letters, symbols) that should be ignored once they appear

Your task is to:

    Convert the initial numeric part of the string to an integer
    Stop parsing when a non-digit character is encountered
    Return the result with the correct sign

Do not use atoi(), strtol(), or similar built-in functions.

 

Example-1

Input: "123abc"
Output: 123


Example-2

Input: "-45!"
Output: -45


Example-3

Input: "42@#"
Output: 42


Example-4

Input: "abc123"
Output: 0


Example-5

Input: "+78x90"
Output: 78
*/

#include <stdio.h>
#include <stdint.h>

int str_to_int(char * str){
    int i = 0;
    int result = 0;
    int negative = 0;
    if(str[0] == '-'){
        negative = 1;
        i++;
    }
    if(str[0] == '+'){
        i++;
    }

    while(*(str+i) != '\0' && (*(str+i) >= '0' && *(str+i) <= '9')) {
        if(negative == 1){
            result = result * 10 - (*(str+i) - '0');
        }
        else{
            result = result * 10 + (*(str+i) - '0');
        }
        i++;
    }
    return result;
}

int main(){
    char str[100];

    fgets(str, sizeof(str), stdin);

    int result = str_to_int(str);
    
    printf("%d\n", result);
    return 0;
}