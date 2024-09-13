#include <stdio.h>
#include <string.h>

int main() {
    char str[100], substr[50];
    int i, j, found, position = -1;

    // Input string and substring
    printf("Enter the main string: ");
    gets(str);
    printf("Enter the substring: ");
    gets(substr);

    int strLen = strlen(str);
    int substrLen = strlen(substr);

    // Finding the position of the substring
    for (i = 0; i <= strLen - substrLen; i++) {
        found = 1;
        for (j = 0; j < substrLen; j++) {
            if (str[i + j] != substr[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            position = i;
            break;
        }
    }

    if (position != -1)
        printf("Substring found at position: %d\n", position);
    else
        printf("Substring not found\n");

    return 0;
}

