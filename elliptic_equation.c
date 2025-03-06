#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k;
    float sum, error, E[10], a[10][10], b[10], new_x[10], old_x[10], tl, tr, tu, tb;

    // Input temperatures at the boundaries
    printf("Enter temperatures at left, right, bottom, and upper part of the plate: \n");
    scanf("%f%f%f%f", &tl, &tr, &tb, &tu);

    // Input the number of grid points
    printf("Enter the number of grid points (n): \n");
    scanf("%d", &n);

    // Initialize coefficient matrix and RHS vector
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            if (i == j)
                a[i][j] = -4; // Diagonal elements
            else if (j == n - i)
                a[i][j] = 0; // Off-diagonal elements
            else
                a[i][j] = 1; // Other elements
        }
        b[i] = 0; // Initialize RHS vector
    }

    // Construct RHS vector based on boundary conditions
    k = 0;
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if ((i - 1) == 0)
                b[k] -= tl;
            if ((i + 1) == n)
                b[k] -= tr;
            if ((j - 1) == 0)
                b[k] -= tb;
            if ((j + 1) == n)
                b[k] -= tu;
            k++;
        }
    }

    // Input accuracy limit
    printf("Enter accuracy limit: \n");
    scanf("%f", &error);

    // Solve the system using Gauss-Seidel method
    for (i = 0; i <= n; i++)
        new_x[i] = 0; // Initial guess

    while (1) {
        for (i = 0; i <= n; i++) {
            sum = b[i];
            for (j = 0; j <= n; j++) {
                if (i != j)
                    sum -= a[i][j] * new_x[j];
            }
            old_x[i] = new_x[i];
            new_x[i] = sum / a[i][i];
            E[i] = fabs((new_x[i] - old_x[i]) / new_x[i]);
        }

        // Check for convergence
        int flag = 1;
        for (i = 0; i <= n; i++) {
            if (E[i] > error) {
                flag = 0;
                break;
            }
        }
        if (flag)
            break;
    }

    // Output the solution
    printf("Solution:\n");
    for (i = 0; i <= n; i++)
        printf("x%d = %6.2f\n", i + 1, new_x[i]);

    return 0;
}