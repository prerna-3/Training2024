#include <stdio.h>
#include <string.h>

int isPalindrome(char* str) {
    int i, j;
    int len = strlen(str);

    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;  // Not a palindrome
        }
    }

    return 1;  // Palindrome
}

int main() {
    char str[100];

    // Input string
    printf("Enter a string: ");
    gets(str);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

