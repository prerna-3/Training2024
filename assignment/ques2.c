#include <stdio.h>

int main() {
    int arr1[100], arr2[100], merged[200], filtered[200];
    int n1, n2, m = 0, f = 0;
    
    // Input the first array
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter elements of first array: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
        merged[m++] = arr1[i]; // Add to merged array
    }

    // Input the second array
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter elements of second array: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
        merged[m++] = arr2[i]; // Add to merged array
    }

    // Filter odd numbers
    for (int i = 0; i < m; i++) {
        if (merged[i] % 2 != 0) { // Check if the number is odd
            filtered[f++] = merged[i];
        }
    }

    // Sort the filtered array (simple bubble sort)
    for (int i = 0; i < f - 1; i++) {
        for (int j = 0; j < f - i - 1; j++) {
            if (filtered[j] > filtered[j + 1]) {
                int temp = filtered[j];
                filtered[j] = filtered[j + 1];
                filtered[j + 1] = temp;
            }
        }
    }

    // Print the filtered and sorted array
    printf("Filtered and sorted array with odd numbers: ");
    for (int i = 0; i < f; i++) {
        printf("%d ", filtered[i]);
    }

    return 0;
}

