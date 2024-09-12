#include <stdio.h>
#include <string.h>

int main() {
    int n, i, charSum = 0, wordSum = 0;
    char searchChar;
    char searchWord[] = "the";

    // Ask for number of lines
    printf("Enter the number of lines: ");
    scanf("%d", &n);
    getchar();  // To consume the newline character left by scanf

    // Array to store the input lines
    char lines[n][100];

    // Input the lines
    printf("Enter %d lines:\n", n);
    for (i = 0; i < n; i++) {
        fgets(lines[i], sizeof(lines[i]), stdin);
    }

    // Ask for the character to search
    printf("Enter the character to search: ");
    scanf("%c", &searchChar);

    // Search for character and word "the" in each line
    for (i = 0; i < n; i++) {
        // Search for character
        for (int j = 0; lines[i][j] != '\0'; j++) {
            if (lines[i][j] == searchChar) {
                printf("Character '%c' found in line %d at position %d\n", searchChar, i + 1, j + 1);
                charSum += (j + 1);
                break;
            }
        }

        // Search for word "the"
        char *wordPos = strstr(lines[i], searchWord);
        if (wordPos) {
            int pos = wordPos - lines[i] + 1;  // Convert to 1-based index
            printf("Word 'the' found in line %d at position %d\n", i + 1, pos);
            wordSum += pos;
        }
    }

    // Print the sums of positions
    printf("Sum of positions for character '%c': %d\n", searchChar, charSum);
    printf("Sum of positions for word 'the': %d\n", wordSum);

    return 0;
}

