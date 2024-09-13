#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_WORDS 50

// Function to reverse the order of words
void reverseOrder(char* str) {
    char* words[MAX_WORDS];
    int count = 0;
    char* token = strtok(str, "|");

    // Collect all words
    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, "|");
    }

    // Print words in reverse order
    for (int i = count - 1; i >= 0; i--) {
        if (i < count - 1) {
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

    reverseOrder(str);

    return 0;
}

