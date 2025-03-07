#include<stdio.h>
#include<math.h>
#define EQUATION(x, y) (2 * (x) * (x) * (y) * (y))  // Poisson equation RHS function

int main() {
    int N;
    double h, tol;

    printf("Enter grid size (N): ");
    scanf("%d", &N);

    printf("Enter grid spacing (h): ");
    scanf("%lf", &h);

    printf("Enter tolerance value: ");
    scanf("%lf", &tol);

    double F[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            F[i][j] = 0.0;  // Initialize with boundary conditions
        }
    }

    double error;
    int iter = 0;

    // Iterative method (Gauss-Seidel) to solve the equation
    do {
        error = 0.0;
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                double old = F[i][j];
                F[i][j] = (F[i+1][j] + F[i-1][j] + F[i][j+1] + F[i][j-1] - h*h * EQUATION(i*h, j*h)) / 4.0;
                error = fmax(error, fabs(F[i][j] - old));
            }
        }
        iter++;
    } while (error > tol);

    printf("Solution after %d iterations:\n", iter);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%0.6lf\t", F[i][j]);
        }
        printf("\n");
    }

    return 0;
}
