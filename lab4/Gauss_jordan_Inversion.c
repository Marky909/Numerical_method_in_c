// C Program for Matrix Inversion using Gauss-Jordan Method
#include <stdio.h>
#include <math.h>

int main() {
    int n, i, k, j, p;
    float pivot, term, a[20][20], inv[20][20];

    /* Inputs */
    /* 1. Reading dimension of matrix */
    printf("Enter dimension of matrix: ");
    scanf("%d", &n);

    /* 2. Reading Matrix */
    printf("Enter elements of matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    /* Initialize inverse matrix as identity matrix */
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                inv[i][j] = 1.0;
            } else {
                inv[i][j] = 0.0;
            }
        }
    }

    /* Gauss-Jordan Method for Inversion */
    for (k = 1; k <= n; k++) {
        pivot = a[k][k];
        /* Normalize the pivot row */
        for (j = 1; j <= n; j++) {
            a[k][j] = a[k][j] / pivot;
            inv[k][j] = inv[k][j] / pivot;
        }

        /* Eliminate other rows */
        for (i = 1; i <= n; i++) {
            if (i != k) {
                term = a[i][k];
                for (j = 1; j <= n; j++) {
                    a[i][j] = a[i][j] - a[k][j] * term;
                    inv[i][j] = inv[i][j] - inv[k][j] * term;
                }
            }
        }
    }

    /* Displaying Inverse Matrix */
    printf("\nMatrix Inverse is:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%8.4f\t", inv[i][j]);
        }
        printf("\n");
    }

    return 0;
}