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
    float val = 0, p, xp, x[10], fx[10], bd[10], h, s, term1, term2, prev;

    // Input number of points
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Input the value at which derivative is needed
    printf("Enter the value at which derivative is needed: ");
    scanf("%f", &xp);

    // Input x and f(x) values
    for (i = 0; i < n; i++) {
        printf("Enter the value of x[%d] and fx[%d]: ", i, i);
        scanf("%f%f", &x[i], &fx[i]);
    }

    // Calculate the interval h
    h = x[1] - x[0];

    // Calculate s
    s = (xp - x[n - 1]) / h;

    // Initialize backward difference array
    for (i = 0; i < n; i++) {
        bd[i] = fx[i];
    }

    // Generate the backward difference table
    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            bd[j] = bd[j + 1] - bd[j];
        }
    }

    // Compute first derivative
    val = bd[n - 2];
    prev = 1;

    for (i = 2; i < n; i++) {
        term1 = 1;
        for (k = 2; k <= i; k++) {
            term1 *= (s + k - 2);
        }
        term2 = (s + i - 1) * prev;
        prev = term1 + term2;
        val += (bd[n - i - 1] * prev) / fact(i);
    }

    val /= h;

    // Output the derivative value
    printf("Value of First Derivative at x = %.4f is %.4f\n", xp, val);

    return 0;
}
