#include <stdio.h>


#define MINUTES_IN_HOUR 60

int main() {
    int total_minutes;  
    int hours, minutes; 

    
    printf("Enter time in minutes: ");
    scanf("%d", &total_minutes);

    
    hours = total_minutes / MINUTES_IN_HOUR;  
    minutes = total_minutes % MINUTES_IN_HOUR; 

    
    printf("%d minutes is equal to %d hours and %d minutes.\n", total_minutes, hours, minutes);

    return 0;
}

