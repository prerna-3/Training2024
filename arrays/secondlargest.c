#include <stdio.h>

int main() {
    int arr[5] = {5, 3, 8, 1, 9};
    int i, largest, secondLargest;

    largest = secondLargest = arr[0];

    for (i = 1; i < 5; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    printf("Second largest element: %d\n", secondLargest);

    return 0;
}

