#include <stdio.h>

int main() {
    int arr[10], i;

    // Initialize array with first 10 natural numbers
    for(i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }

    // Print elements
    printf("Array elements:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

