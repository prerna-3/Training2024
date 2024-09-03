#include <stdio.h>

int main() {
    int score;       
    char grade;      

    
    printf("Enter the student's score: ");
    scanf("%d", &score);

    
    printf("Enter the student's grade (A, B, C, D, or F): ");
    scanf(" %c", &grade); 

    printf("Your score is %d and Grade is %c.\n", score, grade);

    return 0;
}

