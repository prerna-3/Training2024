#include <stdio.h>

int main() {
    int n;  // Number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];  // Declare an array of size n

    // Read array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Print array elements using index
    printf("\nArray elements (using index):\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: %d\n", i, arr[i]);
    }

    // Print array elements using address
    printf("\nArray elements (using address):\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: %d\n", i, *(arr + i));
    }

    return 0;
}

