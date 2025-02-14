#include <stdio.h>

#define f(x) (x)*(x) // Function definition: f(x) = x^2

int main() {
    float x, h, derivative;

    printf("enter the value of x: ");
    scanf("%f",&x);

    printf("enter the value of h: ");
    scanf("%f",&h);

    // Forward difference formula to compute the derivative
    derivative = (f(x + h) - f(x)) / h;

    // Output the result
    printf("Value of Derivative at x = 1: %f\n", derivative);

    return 0;
}