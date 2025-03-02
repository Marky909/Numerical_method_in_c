// C Program for Gauss-Jordan Elimination
#include <stdio.h>
#include <math.h>

int main() {
    int n, i, k, j, p;
    float pivot, term, a[20][20], b[20];

    /* Inputs */
    /* 1. Reading dimension of system of equations */
    printf("Enter dimension of system of equations: ");
    scanf("%d", &n);

    /* 2. Reading coefficients */
    printf("Enter coefficients row-wise:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    /* 3. Reading RHS vector */
    printf("Enter RHS vector:\n");
    for (i = 1; i <= n; i++) {
        printf("b[%d] = ", i);
        scanf("%f", &b[i]);
    }

    /* Gauss-Jordan Elimination */
    for (k = 1; k <= n; k++) {
        pivot = a[k][k];
        /* Normalize the pivot row */
        for (j = 1; j <= n; j++) {
            a[k][j] = a[k][j] / pivot;
        }
        b[k] = b[k] / pivot;

        /* Eliminate other rows */
        for (i = 1; i <= n; i++) {
            if (i != k) {
                term = a[i][k];
                for (j = 1; j <= n; j++) {
                    a[i][j] = a[i][j] - a[k][j] * term;
                }
                b[i] = b[i] - b[k] * term;
            }
        }
    }

    /* Displaying Solution */
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++) {
        printf("x[%d] = %8.4f\n", i, b[i]);
    }

    return 0;
}