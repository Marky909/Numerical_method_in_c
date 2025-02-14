#include <stdio.h>
#include <math.h>

int main() {
    float x[20], f[20][20], k, result, term;
    int n, i, j;

    // Input the number of observations
    printf("Enter the number of data points (n): ");
    scanf("%d", &n);

    // Input the x[i] and f[i] values
    printf("Enter the values of x[i] and f[i]:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("f[%d]: ", i);
        scanf("%f", &f[i][0]);
    }

    // Input the value to be interpolated
    printf("\nEnter the value of k to evaluate f(k): ");
    scanf("%f", &k);

    // Compute the divided difference table
    for (j = 1; j < n; j++) { // Columns of the table
        for (i = 0; i < n - j; i++) { // Rows of the table
            f[i][j] = (f[i + 1][j - 1] - f[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    // Perform Newton's Divided Difference interpolation
    result = f[0][0]; // Initialize with the first value
    for (i = 1; i < n; i++) {
        term = f[0][i]; // Start with the coefficient
        for (j = 0; j < i; j++) {
            term *= (k - x[j]); // Multiply by (k - x[j]) terms
        }
        result += term; // Add to the result
    }

    // Output the result
    printf("\nThe interpolated value at k = %.4f is %.4f\n", k, result);

    return 0;
}

