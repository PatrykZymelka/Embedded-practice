/*
In embedded systems, you often receive hex strings from serial terminals or config files, like "1A3F", and need to convert them into integers — without using strtol(), sscanf(), or other library functions.

Your task is to:

    Read a hex string of up to 4 characters (e.g., "1A3F")
    Convert it into a uint16_t integer
    Handle both uppercase and lowercase (e.g., "af" = "AF" = 175)


Example-1

Input: 1A3F
Output: 6719


Example-2

Input: AF
Output: 175


Example-3

Input: 0000
Output: 0


Example-4

Input: ffff
Output: 65535
*/
#include <stdio.h>
#include <stdint.h>

uint16_t hex_to_dec(char * input){
    uint16_t result = 0;
    int i;
    for(i = 0; i < 4; i++){
        int val = 0;
        if(input[i] >= '0' && input[i] <= '9'){
            val = input[i] - '0'; 
            
        }
        else if(input[i] >= 'A' && input[i] <= 'F'){
            val = 10 + (input[i] - 'A');
        }
        else if(input[i] >= 'a' && input[i] <= 'f'){
            val = 10 + (input[i] - 'a');
        }
        result |= (val << 12-(4*i));
    }
    return result;
}

int main(){

    char input[100];
    scanf("%s", input);

    uint16_t result = hex_to_dec(input);

    printf("%d\n",result);
    return 0;
}