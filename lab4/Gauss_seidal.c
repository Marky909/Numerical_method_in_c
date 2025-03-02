// C Program for Gauss-Seidel Method
#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
    int n, i, j, iter, maxIter;
    float a[20][20], b[20], x[20], xnew[20], sum, error, maxError;

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

    /* 4. Reading maximum iterations */
    printf("Enter maximum iterations: ");
    scanf("%d", &maxIter);

    /* 5. Reading initial values */
    printf("Enter initial values:\n");
    for (i = 1; i <= n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
    }

    /* Gauss-Seidel Iteration */
    printf("\nIteration Results:\n");
    for (iter = 1; iter <= maxIter; iter++) {
        maxError = 0;
        
        for (i = 1; i <= n; i++) {
            sum = b[i];
            for (j = 1; j <= n; j++) {
                if (i != j) {
                    sum = sum - a[i][j] * x[j];
                }
            }
            xnew[i] = sum / a[i][i];
            error = fabs(xnew[i] - x[i]) / fabs(xnew[i]);
            if (error > maxError) {
                maxError = error;
            }
            x[i] = xnew[i]; // Update immediately for Gauss-Seidel
        }

        /* Display iteration results */
        printf("Iteration #%d: ", iter);
        for (i = 1; i <= n; i++) {
            printf("x[%d] = %0.4f  ", i, x[i]);
        }
        printf("\n");

        /* Check for convergence */
        if (maxError < EPSILON) {
            printf("\nConverged after %d iterations\n", iter);
            break;
        }
    }

    if (iter > maxIter) {
        printf("\nDid not converge after %d iterations\n", maxIter);
    }

    /* Displaying Solution */
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++) {
        printf("x[%d] = %0.4f\n", i, x[i]);
    }

    return 0;
}