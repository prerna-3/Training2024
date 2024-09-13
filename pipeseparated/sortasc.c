#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_WORDS 50

// Function to sort words by their length
void sortByLength(char* str) {
    char* words[MAX_WORDS];
    int count = 0;
    char* token = strtok(str, "|");

    // Collect all words
    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, "|");
    }

    // Sort words by length
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strlen(words[i]) > strlen(words[j])) {
                char* temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print the sorted words
    for (int i = 0; i < count; i++) {
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

    sortByLength(str);

    return 0;
}

