/*
You are simulating a system boot-up sequence using function pointers. 

There are 4 states:

void state_init()    { printf("Init"); }
void state_load()    { printf("Load"); }
void state_execute() { printf("Execute"); }
void state_exit()    { printf("Exit"); }

Your Task

    Implement the function run_state_sequence(int start)
    It should execute three states in sequence, starting from the given start index:
        If start = 1 → print Load, Execute, Exit
        If start = 3 → wrap around → print Exit, Init, Load
    ✅You must use a function pointer array
    ❌ Do not use if or switch-case
     

Constraints

    start ∈ [0, 3]
    Always execute exactly three states
    Output each state on a new line


Example-1

Input: 0
Output:
Init
Load
Execute


Example-2

Input: 2
Output:
Execute
Exit
Init


Example-3

Input: 3
Output:
Exit
Init
Load
*/

#include <stdio.h>
#include <stdint.h>

void state_init()    { printf("Init"); }
void state_load()    { printf("Load"); }
void state_execute() { printf("Execute"); }
void state_exit()    { printf("Exit"); }

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

void func_ptr(int n){
    void (*func_p[4])() = {state_init, state_load, state_execute, state_exit};
    for(int i = 0; i < 3; i++){
        int val = (i+n)%4;
        func_p[val]();
    }
    

}


int main(){
    int n;
    scanf("%d", &n);

    func_ptr(n);
    
    return 0;
}