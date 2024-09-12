#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void printEmployee(struct Employee emp) {
    printf("ID: %d\nName: %s\nSalary: %.2f\n", emp.id, emp.name, emp.salary);
}

int main() {
    struct Employee e;
    printf("Enter employee ID: ");
    scanf("%d", &e.id);
    printf("Enter employee name: ");
    scanf("%s", e.name);
    printf("Enter employee salary: ");
    scanf("%f", &e.salary);
    printEmployee(e);
    return 0;
}
