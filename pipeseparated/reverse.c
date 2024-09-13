#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Function to reverse each word
void reverseWords(char* str) {
    char* token = strtok(str, "|");
    char reversed[MAX_LEN];

    while (token != NULL) {
        int len = strlen(token);
        for (int i = 0; i < len; i++) {
            reversed[i] = token[len - i - 1];
        }
        reversed[len] = '\0';  // Null-terminate the reversed string

        if (token != str) {
            printf("|");
        }
        printf("%s", reversed);

        token = strtok(NULL, "|");
    }
    printf("\n");
}

int main() {
    char str[MAX_LEN];

    // Input the pipe-separated string
    printf("Enter the pipe-separated string: ");
    gets(str);

    reverseWords(str);

    return 0;
}

