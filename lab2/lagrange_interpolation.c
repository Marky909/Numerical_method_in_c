#include <stdio.h>
#include <math.h>

int main() {
    float y, x[20], f[20], sum = 0, pf;
    int i, j, n;

    // Input the number of data points
    printf("Enter the number of data points (n): ");
    scanf("%d", &n);

    // Input the value to be interpolated
    printf("Enter the value of y to be interpolated: ");
    scanf("%f", &y);

    // Input the x[i] and f[i] values
    printf("Enter the values of x[i] and f[i]:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("f[%d]: ", i);
        scanf("%f", &f[i]);
    }

    // Perform Lagrange interpolation
    for (i = 0; i < n; i++) {
        pf = 1; // Initialize product term
        for (j = 0; j < n; j++) {
            if (j != i) {
                pf *= (y - x[j]) / (x[i] - x[j]); // Compute product
            }
        }
        sum += f[i] * pf; // Add term to the sum
    }

    // Output the results
    printf("\nThe interpolated value at x = %.4f is %.4f\n", y, sum);

    return 0;
}

