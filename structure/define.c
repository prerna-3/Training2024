#include <stdio.h>

// Define the structure Student
struct Student {
    char name[50];
    int age;
    char grade;
};

int main() {
    struct Student student;

    // Input values for each member of the structure
    printf("Enter student's name: ");
    gets(student.name);
    printf("Enter student's age: ");
    scanf("%d", &student.age);
    printf("Enter student's grade: ");
    scanf(" %c", &student.grade);  // Note the space before %c to consume the newline

    // Print the values
    printf("\nStudent Details:\n");
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Grade: %c\n", student.grade);

    return 0;
}

