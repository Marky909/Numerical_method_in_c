#include <stdio.h>

// Function to calculate factorial
int fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main() {
    int n, i, j, k;
    float v = 0, p, xp, x[10], fx[10], fd[10], h, s;

    // Input number of points
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Input the value at which interpolation is needed
    printf("Enter the value at which interpolated value is needed: ");
    scanf("%f", &xp);

    // Input x and fx values
    for (i = 0; i < n; i++) {
        printf("Enter the value of x[%d] and fx[%d]: ", i, i);
        scanf("%f%f", &x[i], &fx[i]);
    }

    // Calculate the interval h
    h = x[1] - x[0];

    // Calculate s
    s = (xp - x[0]) / h;

    // Initialize the forward difference array
    for (i = 0; i < n; i++) {
        fd[i] = fx[i];
    }

    // Generate the forward difference table
    for (i = 1; i < n; i++) {
        for (j = n - 1; j >= i; j--) {
            fd[j] = fd[j] - fd[j - 1];
        }
    }

    // Calculate the interpolated value
    v = fd[0]; // Initialize with the first term
    for (i = 1; i < n; i++) {
        p = 1; // Initialize product term
        for (k = 1; k <= i; k++) {
            p = p * (s - k + 1);
        }
        v = v + (fd[i] * p) / fact(i); // Add term to the interpolated value
    }

    // Output the interpolated value
    printf("Interpolated value at x = %.4f is %.4f\n", xp, v);

    return 0;
}

