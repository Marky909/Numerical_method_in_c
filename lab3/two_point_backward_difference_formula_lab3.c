#include <stdio.h>

#define f(x) (x)*(x) // Function definition: f(x) = x^2

int main() {
    float h, x, derivative;

   printf("enter the value of x: ");
    scanf("%f",&x);

    printf("enter the value of h: ");
    scanf("%f",&h);

    // Backward difference formula
    derivative = (f(x) - f(x - h)) / h;

    // Output result
    printf("Value of Derivative at x = 1: %f\n", derivative);

    return 0;
}