/*
You are given a null-terminated string containing words separated by a delimiter character (like comma , or space ' ').

Your task is to:

    Split the string into individual tokens based on the delimiter
    Store the tokens in a 2D array of characters (char tokens[10][20])
    Print each token on a new line

Do not use strtok() or any string library functions.

 

Example-1

Input:
str = "cmd1,cmd2,cmd3"
delimiter = ','
Output:
cmd1  
cmd2  
cmd3


Example-2

Input:
str = "ON OFF RESET"
delimiter = ' '
Output:
ON  
OFF  
RESET
*/

#include <stdio.h>
#include <stdint.h>

void split_sentence(char * arr, char result[10][20], char delimiter, int * count){
    int i = 0;
    int word_len = 0;
    while(*(arr+i) != '\0' &&*(arr+i) != '\n'){
        if(arr[i] == delimiter){
            result[*count][word_len++] = '\0';
            (*count)++;
            word_len = 0;
        }
        else{
            result[*count][word_len++] = arr[i];
        }
        i++;
    }
    result[*count][word_len] = '\0';
}

int main(){
    char arr[100];
    fgets(arr,sizeof(arr),stdin);
    char result[10][20];
    char delimiter;
    scanf("%c", &delimiter);
    int count = 0;

    split_sentence(arr, result, delimiter, &count);

    for(int i = 0; i <= count; i++){
        printf("%s ",result[i]);
    }
    


    
    return 0;
}