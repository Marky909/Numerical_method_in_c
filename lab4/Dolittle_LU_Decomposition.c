// C Program for Matrix Factorization using Doolittle LU Decomposition
#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k;
    float sum = 0, a[20][20], u[20][20], l[20][20];

    /* Inputs */
    /* 1. Reading dimension of the matrix */
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

    /* Initialize L and U matrices */
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                l[i][j] = 1;
            } else {
                l[i][j] = 0;
            }
            u[i][j] = 0;
        }
    }

    /* Compute Elements of L and U matrices */
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            sum = 0;
            for (k = 1; k < i; k++) {
                sum = sum + (l[i][k] * u[k][j]);
            }
            u[i][j] = a[i][j] - sum;
        }
        for (j = i + 1; j <= n; j++) {
            sum = 0;
            for (k = 1; k < i; k++) {
                sum = sum + (l[j][k] * u[k][i]);
            }
            l[j][i] = (a[j][i] - sum) / u[i][i];
        }
    }

    /* Displaying Results */
    printf("\n*********** L Matrix **********\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%8.4f\t", l[i][j]);
        }
        printf("\n");
    }

    printf("\n*********** U Matrix **********\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%8.4f\t", u[i][j]);
        }
        printf("\n");
    }

    return 0;
}