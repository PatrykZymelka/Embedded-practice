/*
In C, strings are terminated by a null character '\0'. Your task is to implement a custom strlen() function that calculates the length of a string without using any built-in functions.

You will be given a string of maximum of 100 characters. Return the number of characters before the null terminator.

 

Example-1

Input: "Embedded"
Output: 8

 

Example-2

Input: "C is powerful"
Output: 13

 

Example-3

Input: ""
Output: 0
*/

#include <stdio.h>
#include <stdint.h>

int custom_strlen(char * s){
    int count = 0;
    while(*(s+count) != '\0'){
        count++;
    }

    return count;
}

int main(){
    char arr[100];
    scanf("%s", &arr);

    int result = custom_strlen(arr);
    printf("%d\n", result);
    
    return 0;
}