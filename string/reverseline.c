#include <stdio.h>
#include <string.h>

int main() {
    char line[100], temp;
    int i, j;

    // Input line
    printf("Enter a line: ");
    gets(line);

    // Reversing the line
    i = 0;
    j = strlen(line) - 1;

    while (i < j) {
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
        i++;
        j--;
    }

    printf("Reversed line: %s\n", line);

    return 0;
}

