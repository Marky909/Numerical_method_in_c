#include <stdio.h>

// Function to calculate factorial
int fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main() {
    int n, i, j;
    float x[10], fx[10], fd[10], h, xp, s, val = 0;

    // Input number of points
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Input the value at which derivative is needed
    printf("Enter the value at which derivative is needed: ");
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

    // Calculate the first derivative using Newton's forward difference formula
    val = fd[1]; // First term of the derivative formula
    for (i = 2; i < n; i++) {
        float term = 1;
        for (j = 2; j <= i; j++) {
            term *= (s - j + 2);
        }
        val += (fd[i] * term) / fact(i);
    }

    // Divide by h to get the derivative
    val /= h;

    // Output the derivative value
    printf("Value of First Derivative at x = %.4f is %.4f\n", xp, val);

    return 0;
}