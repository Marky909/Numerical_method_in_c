#include<stdio.h>
#include<math.h>
#define f(x) (3*x - cos(x) - 1)
#define g(x) (3 + sin(x))
#define e 0.0001

int main(){
    float x0, x1, f0, g0, f1;
    int i = 0, N;

    // Taking inputs from the user
    printf("Enter initial guess (x0): ");
    scanf("%f", &x0);

    printf("Enter maximum iterations: ");
    scanf("%d", &N);

    do {
        g0 = g(x0);
        f0 = f(x0);

        if(g0 == 0.0) {
            printf("\a\nMathematical Error: Derivative is zero!\n");
            printf("Exiting from the program execution!\n");
            return 1;
        }

        // Newton Raphson formula
        x1 = x0 - f0 / g0;
        f1 = f(x1);

        i++;

        printf("Iteration: %d\n", i);
        printf("Intermediate root: %.6f\n", x1);
        printf("Check for tolerance: %.6f\n", f1);

        x0 = x1;

        if(i >= N) {
            printf("\nThe method did not converge within the maximum number of iterations.\n");
            return 1;
        }

    } while(fabs(f1) > e);

    // Output the approximate root
    printf("\n\nThe approximate root is %.6f\n", x1);

    return 0;
}

