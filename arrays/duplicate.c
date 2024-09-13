#include <stdio.h>

int main() {
    int arr[5] = {5, 3, 8, 3, 9};
    int i, j, k;

    printf("Array after removing duplicates: ");
    for (i = 0; i < 5; i++) {
        if (arr[i] != -1) {
            printf("%d ", arr[i]);
            for (j = i + 1; j < 5; j++) {
                if (arr[i] == arr[j]) {
                    arr[j] = -1; // Mark duplicate elements
                }
            }
        }
    }

    return 0;
}

