#include <stdio.h>
#include <math.h>

// Define the source function
#define g(x, y) (2 * (x) * (x) * (y) * (y))

int main() {
    int n, i, j, k;
    float sum, error, E[10], a[10][10], b[10], new_x[10], old_x[10], tl, tr, tu, tb, h;

    // Input grid dimension and boundary temperatures
    printf("Enter dimension of the plate: \n");
    scanf("%d", &n);
    printf("Enter grid spacing (h): \n");
    scanf("%f", &h);
    printf("Enter temperatures at left, right, bottom, and upper part of the plate: \n");
    scanf("%f%f%f%f", &tl, &tr, &tb, &tu);

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
    }

    // Construct RHS vector
    k = 0;
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            b[k] = h * h * g(i, j); // Source term
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