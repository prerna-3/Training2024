#include <stdio.h>

int main() {
    int arr[5], i, max, min;

    // Reading elements into the array
    printf("Enter 5 elements:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    max = min = arr[0];  // Initialize max and min

    // Find max and min
    for(i = 1; i < 5; i++) {
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    return 0;
}

