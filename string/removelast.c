#include <stdio.h>
#include <string.h>

// Function to remove the last occurrence of a word in the string
void removeLastOccurrence(char* str, const char* word) {
    int strLen = strlen(str);
    int wordLen = strlen(word);
    int i, j, lastPos = -1;

    // Find the last occurrence of the word in the string
    for (i = 0; i <= strLen - wordLen; i++) {
        // Check if the word matches at the current position
        if (strncmp(&str[i], word, wordLen) == 0) {
            // Ensure that the word is separate (either ends of the string or surrounded by spaces)
            if ((i == 0 || str[i - 1] == ' ') && (str[i + wordLen] == ' ' || str[i + wordLen] == '\0')) {
                lastPos = i;  // Update last occurrence position
            }
        }
    }

    // If the word is found, remove it from the string
    if (lastPos != -1) {
        // Shift the characters to the left to remove the word
        for (j = lastPos; j <= strLen - wordLen; j++) {
            str[j] = str[j + wordLen];
        }
    }
}

int main() {
    char str[200], word[50];

    // Input the string
    printf("Enter the string: ");
    gets(str);

    // Input the word to remove
    printf("Enter the word to remove: ");
    gets(word);

    removeLastOccurrence(str, word);

    // Output the modified string
    printf("String after removing last occurrence of '%s':\n%s\n", word, str);

    return 0;
}

