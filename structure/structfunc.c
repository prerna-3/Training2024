#include <stdio.h>

// Define the structure Employee
struct Employee {
    int id;
    char name[50];
    float salary;
};

// Function to print employee details
void printEmployee(struct Employee emp) {
    printf("Employee ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);
}

int main() {
    struct Employee emp;

    // Input employee details
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    getchar();  // Consume newline character left by scanf
    printf("Enter Employee Name: ");
    gets(emp.name);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);

    // Print employee details using the function
    printf("\nEmployee Details:\n");
    printEmployee(emp);

    return 0;
}

