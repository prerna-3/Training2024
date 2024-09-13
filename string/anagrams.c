#include <stdio.h>
#include <string.h>

void sortString(char* str) {
    int i, j;
    char temp;
    int len = strlen(str);

    // Bubble sort to sort the string
    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int areAnagrams(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2)) {
        return 0;  // Different lengths cannot be anagrams
    }

    sortString(str1);
    sortString(str2);

    return strcmp(str1, str2) == 0;
}

int main() {
    char str1[100], str2[100];

    // Input strings
    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string: ");
    gets(str2);

    if (areAnagrams(str1, str2)) {
        printf("The strings are anagrams of each other.\n");
    } else {
        printf("The strings are not anagrams of each other.\n");
    }

    return 0;
}

