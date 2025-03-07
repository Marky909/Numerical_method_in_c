#include<stdio.h>
#include<math.h>

// Function to calculate factorial
int fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return (n * fact(n - 1));
}

int main() {
    float x, x0, yx0, yx, fdy, sdy, tdy;

    // Input initial values of x and y
    printf("Enter initial values of x0 & yx0: \n");
    scanf("%f%f", &x0, &yx0);

    // Input x at which the function is to be evaluated
    printf("Enter x at which function is to be evaluated: \n");
    scanf("%f", &x);

    // Calculate derivatives
    fdy = (x0) * (x0) + (yx0) * (yx0); // First Derivative
    sdy = 2 * (x0) + 2 * (yx0) * fdy;  // Second Derivative
    tdy = 2 + 2 * yx0 * sdy + 2 * fdy * fdy; // Third Derivative

    // Calculate the value of y(x) using Taylor's series expansion
    yx = yx0 + (x - x0) * fdy + (x - x0) * (x - x0) * sdy / fact(2) + (x - x0) * (x - x0) * (x - x0) * tdy / fact(3);

    // Output the result
    printf("Function value at x = %f is %f\n", x, yx);

    return 0;
}