#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 2, 1};
    int i, flag = 1;

    for (i = 0; i < 5 / 2; i++) {
        if (arr[i] != arr[5 - i - 1]) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("Array is a palindrome\n");
    else
        printf("Array is not a palindrome\n");

    return 0;
}

