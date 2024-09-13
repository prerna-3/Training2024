#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_WORDS 50

// Function to print unique words from the string
void findUniqueWords(char* str) {
    char* words[MAX_WORDS];
    int count = 0, i, j;
    char* token = strtok(str, "|");

    // Collect all words
    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, "|");
    }

    // Print unique words
    for (i = 0; i < count; i++) {
        int isUnique = 1;
        for (j = 0; j < i; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            if (i > 0) {
                printf("|");
            }
            printf("%s", words[i]);
        }
    }
    printf("\n");
}

int main() {
    char str[MAX_LEN];

    // Input the pipe-separated string
    printf("Enter the pipe-separated string: ");
    gets(str);

    findUniqueWords(str);

    return 0;
}

