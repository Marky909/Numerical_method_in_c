#include <stdio.h>
#include <math.h>

// Define the Picard approximations
#define y1(x) (2 + (x) - (2.0 / 3.0) * pow(x, 3))
#define y2(x) (2 + (x) + pow(x, 2) - (2.0 / 3.0) * pow(x, 3) + pow(x, 4) / 4.0)
#define y3(x) (2 + (x) + pow(x, 2) - pow(x, 4) / 3.0 - pow(x, 5) / 15.0)

int main() {
    float x, x0, y0, y;

    // Input initial values of x and y
    printf("Enter initial values of x0 and y0: \n");
    scanf("%f%f", &x0, &y0);

    // Input x at which the function is to be evaluated
    printf("Enter x at which function is to be evaluated: \n");
    scanf("%f", &x);

    // Compute the function value using Picard's method
    y = y0 + y1(x); // First approximation
    y = y0 + y2(x); // Second approximation
    y = y0 + y3(x); // Third approximation

    // Output the result
    printf("Function value at x = %f is %f\n", x, y);

    return 0;
}