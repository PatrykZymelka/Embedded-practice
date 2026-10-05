/*
You are given two integer variables: n1 and n2.

Task:

    Initially, a pointer points to n1.
    Pass the address of this pointer (int **pp) to a function.
    Inside the function, decide:
    If the value at pointer is even, reassign it to point to n2.
    If the value is odd, keep pointing to n1.
    Finally, print the value where pointer points.
     

Example-1

Input: n1 = 10, n2 = 50
Output: 50

(10 is even ➔ reassign to n2)


Example-2

Input: n1 = 7, n2 = 100
Output: 7

(7 is odd ➔ keep pointing to n1)


Example-3

Input: n1 = 22, n2 = 88
Output: 88

(22 is even ➔ reassign to n2)
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

void double_pointer(int ** ptr, int * ptr2){

    if(**ptr %2 == 0){
        *ptr = ptr2;
    }


}

int main(){
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    int * ptr = &n1;
    int * ptr2 = &n2;
    double_pointer(&ptr, ptr2);


    
    return 0;
}