#include <stdio.h>
#include <string.h>

// Function to replace the first occurrence of a character in a string
void replaceFirstOccurrence(char* str, char oldChar, char newChar) {
    int i;
    int len = strlen(str);

    // Traverse the string to find the first occurrence of oldChar
    for (i = 0; i < len; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;  // Replace with newChar
            break;  // Exit loop after replacing the first occurrence
        }
    }
}

int main() {
    char str[100];
    char oldChar, newChar;

    // Input the string
    printf("Enter the string: ");
    gets(str);

    // Input characters to replace and replace with
    printf("Enter the character to replace: ");
    scanf("%c", &oldChar);
    getchar();  // Consume newline character left by scanf
    printf("Enter the character to replace with: ");
    scanf("%c", &newChar);

    replaceFirstOccurrence(str, oldChar, newChar);

    // Output the modified string
    printf("String after replacing '%c' with '%c': %s\n", oldChar, newChar, str);

    return 0;
}

