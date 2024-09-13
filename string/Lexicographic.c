#include <stdio.h>
#include <string.h>

void sortStrings(char arr[][50], int n) {
    char temp[50];
    int i, j;

    // Bubble sort to sort the array of strings
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int main() {
    int n, i;
    char arr[10][50];

    // Input number of strings
    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar(); // To consume newline character left by scanf

    // Input strings
    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        gets(arr[i]);
    }

    sortStrings(arr, n);

    printf("Strings in lexicographic order:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}

