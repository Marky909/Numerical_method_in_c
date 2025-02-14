#include<stdio.h>
#include<math.h>
#define f(x) (x*x - 4*x - 10)
#define e 0.0001

int main(){
    float x0, x1, x2, f0, f1, f2;
    int i = 0, N;

    // Taking inputs from the user
    printf("Enter the value of x0 and x1: ");
    scanf("%f%f", &x0, &x1);

    printf("Enter maximum iterations: ");
    scanf("%d", &N);

    do {
        f0 = f(x0);
        f1 = f(x1);

        if(f0 == f1) {
            printf("\a\nMathematical Error: Division by zero!\n");
            printf("Exiting from the program execution!\n");
            return 1;
        }

        // Secant method formula
        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2);

        i++;

        printf("Iteration: %d\n", i);
        printf("Intermediate root: %.6f\n", x2);
        printf("Check for tolerance: %.6f\n", f2);

        // Update variables for next iteration
        x0 = x1;
        x1 = x2;

        if(i >= N) {
            printf("\nThe method did not converge within the maximum number of iterations.\n");
            return 1;
        }

    } while(fabs(f2) > e);

    // Output the approximate root
    printf("\n\nThe approximate root is %.6f\n", x2);

    return 0;
}

