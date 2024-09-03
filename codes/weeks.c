#include <stdio.h>


#define DAYS_IN_WEEK 7

int main() {
    int total_days;
    int weeks, days; 

    
    printf("Enter the number of days: ");
    scanf("%d", &total_days);

    
    weeks = total_days / DAYS_IN_WEEK;  
    days = total_days % DAYS_IN_WEEK;   

    
    printf("%d days are %d weeks, %d days.\n", total_days, weeks, days);

    return 0;
}

