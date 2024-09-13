#include <stdio.h>
#include <string.h>

void removeDuplicates(char* str) {
    int i, j, k;
    int len = strlen(str);

    for (i = 0; i < len; i++) {
        for (j = i + 1; str[j] != '\0'; j++) {
            if (str[i] == str[j]) {
                // Shift characters to the left
                for (k = j; str[k] != '\0'; k++) {
                    str[k] = str[k + 1];
                }
                j--;  // Stay at the same index to check again
            }
        }
    }
}

int main() {
    char str[100];

    // Input string
    printf("Enter a string: ");
    gets(str);

    removeDuplicates(str);

    printf("String after removing duplicates: %s\n", str);

    return 0;
}

