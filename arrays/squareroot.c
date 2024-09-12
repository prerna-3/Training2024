#include <stdio.h>
#include <math.h>

int main() {
    int number;
    int lowerSquare, upperSquare, closest;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    int lowerRoot = (int)sqrt(number);
    int upperRoot = lowerRoot + 1;

    lowerSquare = lowerRoot * lowerRoot;
    upperSquare = upperRoot * upperRoot;

    if (number - lowerSquare <= upperSquare - number) {
        closest = lowerSquare;
    } else {
        closest = upperSquare;
    }

    printf("The closest integer having a whole number square root is: %d\n", closest);

    return 0;
}

