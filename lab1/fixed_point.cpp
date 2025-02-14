#include<stdio.h>
#include<math.h>
#define f(x) (cos(x) - 3*x + 1)
#define g(x) ((1 + cos(x)) / 3)
#define e 0.0001

int main(){
    int i = 0, N;
    float x0, x1;

    // Taking inputs from the user
    printf("Enter initial guess (x0): ");
    scanf("%f", &x0);

    printf("Enter maximum iterations: ");
    scanf("%d", &N);

    do {
        x1 = g(x0);

        i++;

        printf("Iteration: %d\n", i);
        printf("Intermediate root: %.6f\n", x1);
        printf("Check for tolerance: %.6f\n", f(x1));

        if(i >= N) {
            printf("\nThe method did not converge within the maximum number of iterations.\n");
            return 1;
        }

        x0 = x1;

    } while(fabs(f(x1)) > e);

    // Output the approximate root
    printf("\n\nThe approximate root is %.6f\n", x1);

    return 0;
}

