#include <stdio.h>

int main() {
    int arr[5], i, search, found = 0;

    // Reading elements into the array
    printf("Enter 5 elements:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &search);

    // Search for the element
    for(i = 0; i < 5; i++) {
        if(arr[i] == search) {
            printf("Element found at index: %d\n", i);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Element not found.\n");
    }

    return 0;
}

