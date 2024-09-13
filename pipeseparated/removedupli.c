#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_WORDS 50

// Function to remove duplicate words from the string
void removeDuplicates(char* str) {
    char* words[MAX_WORDS];
    int count = 0, i, j;
    char temp[MAX_LEN];
    char* token = strtok(str, "|");

    // Collect all words
    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, "|");
    }

    // Remove duplicates
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                // Shift words to remove duplicate
                for (int k = j; k < count - 1; k++) {
                    words[k] = words[k + 1];
                }
                count--;
                j--;
            }
        }
    }

    // Print the result
    for (i = 0; i < count; i++) {
        if (i > 0) {
            printf("|");
        }
        printf("%s", words[i]);
    }
    printf("\n");
}

int main() {
    char str[MAX_LEN];

    // Input the pipe-separated string
    printf("Enter the pipe-separated string: ");
    gets(str);

    removeDuplicates(str);

    return 0;
}

