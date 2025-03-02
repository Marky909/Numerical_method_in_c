// C Program for Gauss Elimination with Partial Pivoting
#include <stdio.h>
#include <math.h>

int main() {
    int n, i, k, j, p, row;
    float pivot, temp, largest, term, sum = 0, a[20][20], b[20], x[20];

    /* Inputs */
    /* 1. Reading dimension of system of equations */
    printf("Enter dimension of system of equations: ");
    scanf("%d", &n);

    /* 2. Reading coefficients of augmented matrix */
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

    /* Forward Elimination with Pivoting */
    for (k = 1; k <= n - 1; k++) {
        largest = fabs(a[k][k]);
        row = k;

        for (p = k + 1; p <= n; p++) {
            if (fabs(a[p][k]) > largest) {
                largest = fabs(a[p][k]);
                row = p;
            }
        }

        /* Swapping rows */
        if (row != k) {
            for (p = 1; p <= n; p++) {
                temp = a[k][p];
                a[k][p] = a[row][p];
                a[row][p] = temp;
            }
            temp = b[k];
            b[k] = b[row];
            b[row] = temp;
        }

        pivot = a[k][k];

        for (i = k + 1; i <= n; i++) {
            term = a[i][k] / pivot;
            for (j = 1; j <= n; j++) {
                a[i][j] = a[i][j] - a[k][j] * term;
            }
            b[i] = b[i] - b[k] * term;
        }
    }

    /* Back Substitution */
    x[n] = b[n] / a[n][n];
    for (i = n - 1; i >= 1; i--) {
        sum = 0;
        for (j = i + 1; j <= n; j++) {
            sum = sum + a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }

    /* Displaying Solution */
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++) {
        printf("x[%d] = %8.4f\n", i, x[i]);
    }

    return 0;
}