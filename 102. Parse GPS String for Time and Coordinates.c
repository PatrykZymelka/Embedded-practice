/*
You are given a $GPRMC NMEA string from a GPS module in the following simplified format:

$GPRMC,<time>,<status>,<lat>,<NS>,<long>,<EW>,...

Your task is to:

    Extract and print:
     
        UTC time in HH:MM:SS format (first field after $GPRMC)
        Latitude with direction (lat NS) : NS- North South
        Longitude with direction (long EW) : EW- East West

Assume:

    Input will always follow this format
    You only need to extract and print the first 7 fields
    Do not validate checksum or GPS fix status
     

Example-1

Input:
$GPRMC,123519,A,4807.038,N,01131.000,E
Output:
Time: 12:35:19  
Latitude: 4807.038 N  
Longitude: 01131.000 E


Example-2

Input:
$GPRMC,083559,A,3745.678,N,12227.890,W
Output:
Time: 08:35:59  
Latitude: 3745.678 N  
Longitude: 12227.890 W
*/

#include <stdio.h>
#include <stdint.h>

void divide_and_print_coordinates(char * arr,char result[7][20],char delimiter){
    int i = 0;
    int count = 0;
    int j = 0;
    while(arr[i] != '\0' && arr[i] != '\n'){
        if(arr[i] == delimiter){
            result[count][j] = '\0';
            count++;
            j = 0;
        }
        else{
            result[count][j] = arr[i];
            j++;
        }
        i++;
    }
    result[count][j] = '\0';
    printf("Time: %c%c:%c%c:%c%c\n",result[1][0],result[1][1],result[1][2],result[1][3],result[1][4],result[1][5]);
    printf("Latitude: %s %s\nLongitude: %s %s\n", result[3], result[4], result[5], result[6]);
}

int main(){
    char arr[100];
    fgets(arr, sizeof(arr), stdin);
    char delimiter = ',';
    char results[7][20];

    divide_and_print_coordinates(arr,results,delimiter);

    
    return 0;
}