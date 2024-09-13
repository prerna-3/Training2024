#include <stdio.h>

int main() {
    int arr[5], i, sum = 0;
    float avg;

    // Reading elements into the array
    printf("Enter 5 elements:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate sum
    for(i = 0; i < 5; i++) {
        sum += arr[i];
    }

    avg = sum / 5.0;  // Calculate average

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);

    return 0;
}

