#include <stdio.h>

int main() {
    int arr[5], i;

    // Reading elements into the array
    printf("Enter 5 elements:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Print elements in reverse order
    printf("Reversed array:\n");
    for(i = 4; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    return 0;
}

