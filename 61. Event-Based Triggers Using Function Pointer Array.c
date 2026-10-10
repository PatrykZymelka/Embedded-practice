/*
You are building a simple event handling system where different event codes (0 to 4) trigger different actions.

Each event type corresponds to a specific function:
Event Code	Trigger Type	Function
0	Button Press	on_button()
1	Timer Expire	on_timer()
2	UART Received	on_uart()
3	Power On	on_power()
4	Error Detected	on_error()

You must:

    Implement a function pointer array
    Trigger the correct function based on the input event code
    If the code is outside the 0–4 range, print "Unhandled Event"
     

Example-1

Input: 1
Output: Timer Expired


Example-2

Input: 3
Output: Power On


Example-3

Input: 5
Output: Unhandled Event
*/

#include <stdio.h>
#include <stdint.h>
void on_button(){printf("Button Press\n"); }
void on_timer(){ printf("Timer Expired\n"); }
void on_uart(){ printf("UART received\n"); }
void on_power(){ printf("Power On\n"); }
void on_error(){ printf("Error detected\n"); }

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

void func_handler(int n){
    if(n < 0 || n > 4){
        printf("Unhandled Event\n");
        return;
    }
    void (*fun[5])() = {on_button, on_timer, on_uart, on_power, on_error};
    fun[n]();
}

int main(){
    int n;
    scanf("%d", &n);

    func_handler(n);
    
    return 0;
}