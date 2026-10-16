/*
In real embedded systems, you often store device status or sensor data in arrays of structs. 
You might need to filter only the relevant records based on a field — for example, sensors above a certain threshold.

Your task is to:

    Read n sensor records (each having a name and a value)
    Print only those records whose value >= threshold

Struct Format

Each record contains:

    char name[10]
    uint8_t value
     

Example-1

Input:
n = 4, threshold = 50  
Sensors:  
T1 45  
T2 67  
T3 10  
T4 90

Output:
T2 67  
T4 90


Example-2

Input:
n = 3, threshold = 100  
Sensors:  
A1 99  
A2 100  
A3 101

Output:
A2 100  
A3 101
*/

#include <stdio.h>
#include <stdint.h>

typedef struct{
    char name[10];
    uint8_t value;
}Sensor;

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



int main(){
    int n, threshold;
    scanf("%d %d", &n, &threshold);

    Sensor s[n];


    for(int i = 0; i < n; i++){
        scanf("%s %d", s[i].name, &s[i].value);
    }

    for(int i = 0; i < n; i++){
        if(s[i].value >= threshold){
            printf("%s %d\n",s[i].name, s[i].value);
        }  
    }
    
    return 0;
}