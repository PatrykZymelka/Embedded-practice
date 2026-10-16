/*
You are given a null-terminated string representing a floating-point number, which may contain:

    An optional sign (+ or -)
    A decimal point
    Only valid digits and one dot

Your task is to convert this string to its floating-point value (float), without using standard library functions like atof() or strtof().

Do not handle scientific notation (e.g., "1.2e5").


Example-1

Input: "123.45"
Output: 123.45


Example-2

Input: "-0.75"
Output: -0.75


Example-3

Input: "100"
Output: 100.00


Example-4

Input: "+9.99"
Output: 9.99
*/

#include <stdio.h>
#include <stdint.h>

float str_to_float(char * str){
    int  i = 0;
    int negative = 0;
    float result = 0.0;
    int divider = 0;
    float decimal = 0.00;
    int dec_places = 0;
    if(str[0] == '-' || str[0] == '+'){
        if(str[0] == '-'){
            negative = 1;
        }
        i++;
    }
    while(*(str + i) != '\0'){
        if(str[i] == '.'){
            divider = 1;
        }
        else if(divider == 0){
            if(negative == 1){
                result = result * 10.0 - (float)(str[i] - '0');
            }
            else{
                result = result * 10.0 + (float)(str[i] - '0');
            } 
        }

        else if(divider == 1 && str[i] != '\n'){
            if(negative == 1){
                decimal = decimal * 10.0 - (float)(str[i] - '0');
            }
            else{
                decimal = decimal * 10.0 + (float)(str[i] - '0');
            } 
            dec_places++;
        }
        i++;
    }
    for(int j = 0; j < dec_places;j++){
        decimal = decimal / 10.0;
    }

    return result + decimal;
}

int main(){
    char str[100];
    fgets(str, sizeof(str), stdin);

    float result = str_to_float(str); 
    
    printf("%.3f\n",result);
    return 0;
}