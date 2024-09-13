#include <stdio.h>
#include <string.h>

// Function to check if a substring is a palindrome
int isPalindrome(char* str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;  // Not a palindrome
        }
        start++;
        end--;
    }
    return 1;  // It is a palindrome
}

int main() {
    char str[100];
    int score = 0;
    int len, i;

    // Input string
    printf("Enter the string: ");
    scanf("%s", str);

    len = strlen(str);

    // Check for palindromes of length 4
    for (i = 0; i <= len - 4; i++) {
        if (isPalindrome(str, i, i + 3)) {
            score += 5;
        }
    }

    // Check for palindromes of length 5
    for (i = 0; i <= len - 5; i++) {
        if (isPalindrome(str, i, i + 4)) {
            score += 10;
        }
    }

    // Output the final score
    printf("Final score: %d\n", score);

    return 0;
}

