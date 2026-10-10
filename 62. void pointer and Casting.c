/*
You are writing a utility function that adds two values — but the values can be either:

    int, or
    float

You will be given void* pointing to the first and second value and a char type specifier: 'i' for int, 'f' for float.

Your task is to:

    Cast the void* to appropriate type based on the specifier
    Perform the addition
    Print the result (as integer or float)

Use proper void* casting and dereferencing logic


Example-1

Input: type = i, a = 10, b = 20
Output: 30


Example-2

Input: type = f, a = 3.5, b = 2.5
Output: 6.0


Example-3

Input: type = i, a = -5, b = 7
Output: 2
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

void func(char c, void * ptr1, void * ptr2){

    if(c == 'i'){
        printf("%d", *(int*)ptr1);
    }
    else if(c == 'f'){
        printf("%.2f", *(float*)ptr2);
    }

}

int main(){
    char c;
    scanf("%c", &c);
    if(c != 'i' && c != 'f'){
        printf("Not a valid input\n");
        return -1;
    }
    int a = 5;
    float b = 4.2;
    void * ptr1 = &a;
    void * ptr2 = &b; 
    
    func(c, ptr1, ptr2);

    return 0;
}