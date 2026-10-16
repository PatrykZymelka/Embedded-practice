/*
In embedded CLI (command-line interface) systems, you often need to parse commands typed by the user into tokens (like command and its arguments). 
A lightweight parser is used to extract each word (separated by spaces) into an array of strings.

Your task is to:

    Read a single input line (up to 100 characters)
    Split it into words separated by one or more spaces
    Print each token on a new line
    Do not use strtok() or any string library function (except gets() or scanf())


Example-1

Input:
led set 3 on

Output:
led  
set  
3  
on


Example-2

Input:
 uart   config 9600 8N1

Output:
uart  
config  
9600  
8N1


Example-3

Input:
status

Output:
status
*/

#include <stdio.h>
#include <stdint.h>

void split_and_print_arr(const char arr[]){
    int i = 0;
    char delimiter = ' ';
    int out_of_word = 1;
    int count = 0;
    int j = 0;
    char result[10][20];
    while(arr[i] != '\0'){
        if(arr[i] == delimiter && out_of_word == 0){
            result[count][j] = '\0';
            count++;
            j = 0;
            out_of_word = 1;
        }
        else if(arr[i] != delimiter && arr[i] != '\n'){
            result[count][j] = arr[i];
            j++;
            out_of_word = 0;
        }
        i++;
    }
    result[count][j] = '\0';
    count++;

    for(int k = 0; k < count; k++){
        printf("%s\n",result[k]);
    }
}

int main(){
    char arr[100];
    fgets(arr, sizeof(arr), stdin);
    
    split_and_print_arr(arr);
    
    return 0;
}