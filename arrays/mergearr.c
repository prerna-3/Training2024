#include <stdio.h>

int main() {
    int arr1[3], arr2[3], merged[6], i;

    // Reading elements into the first array
    printf("Enter 3 elements for the first array:\n");
    for(i = 0; i < 3; i++) {
        scanf("%d", &arr1[i]);
    }

    // Reading elements into the second array
    printf("Enter 3 elements for the second array:\n");
    for(i = 0; i < 3; i++) {
        scanf("%d", &arr2[i]);
    }

    // Merging the arrays
    for(i = 0; i < 3; i++) {
        merged[i] = arr1[i];
        merged[i + 3] = arr2[i];
    }

    // Print merged array
    printf("Merged array:\n");
    for(i = 0; i < 6; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}

