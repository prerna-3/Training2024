#include <stdio.h>

int main() {
    int arr[5], i;

    // Reading elements into the array using index
    printf("Enter 5 elements:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Printing elements using index
    printf("Elements using index:\n");
    for(i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // Printing elements using address
    printf("Elements using address:\n");
    for(i = 0; i < 5; i++) {
        printf("%d ", *(arr + i));
    }

    return 0;
}

