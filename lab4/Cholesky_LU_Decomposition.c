// Program to Factorize the Matrix by using Cholesky Decomposition
#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k;
    float a[20][20], l[20][20], u[20][20], temp;

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

    /* Initialize L and U matrices to zero */
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            l[i][j] = 0;
            u[i][j] = 0;
        }
    }

    /* Calculate Elements of U matrix */
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            temp = 0;
            if (i == j) {
                for (k = 1; k < i; k++) {
                    temp += (u[k][i] * u[k][i]);
                }
                u[i][i] = sqrt(a[i][i] - temp);
            } else {
                for (k = 1; k < i; k++) {
                    temp += (u[k][i] * u[k][j]);
                }
                u[i][j] = (a[i][j] - temp) / u[i][i];
            }
        }
    }

    /* Find Transpose of U Matrix (L matrix) */
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            l[j][i] = u[i][j];
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
