#include <stdio.h>

int main() {
    int arr[5] = {5, 3, 8, 3, 9};
    int i, j, count;

    printf("Element occurrences:\n");
    for (i = 0; i < 5; i++) {
        count = 1;
        if (arr[i] != -1) { // To avoid counting duplicates
            for (j = i + 1; j < 5; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    arr[j] = -1; // Mark as counted
                }
            }
            printf("%d occurs %d times\n", arr[i], count);
        }
    }

    return 0;
}

