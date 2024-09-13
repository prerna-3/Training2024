#include <stdio.h>

int main() {
    int matrix[2][2] = {{1, 2}, {3, 4}};
    int transpose[2][2];
    int i, j;

    // Calculating transpose
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Printing transpose
    printf("Transpose of the matrix:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}

