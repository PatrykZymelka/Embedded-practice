/*
In embedded systems, numeric values often need to be converted into printable string format (e.g., for UART or display output), 
but you may not have access to standard C library functions like itoa() or sprintf().

Your task is to:

    Read a signed integer
    Convert it to its string representation and
    Print each character with a space between characters
    Do not use itoa(), sprintf() or string libraries
     

Example-1

Input: 123
Output: 1 2 3


Example-2

Input: -45
Output: - 4 5


Example-3

Input: 0
Output: 0
*/

#include <stdio.h>
#include <stdint.h>

void int_to_string(int input, char * output){
    int i = 0;
    if(input == 0){
        printf("0");
        return;
    }
    if(input < 0){
        input = -input;
        output[0] = '-';
        i++;
    }
    int count = 0;
    int temp = input;
    while(temp != 0){
        count++;
        temp = temp /10;
    }
    for(int j = 0;j<count;j++){
        int val = (input%10);
        output[count-1-j] = val + '0';
        input = input / 10;
    }
    output[count] = '\0';
}


int main(){
    int input;
    scanf("%d", &input);
    char output[100];
    
    int_to_string(input, output);


    printf("%s", output);
    
    return 0;
}