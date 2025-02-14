#include <stdio.h>
#include <math.h>

// Function prototypes
void linearRegression();
void exponentialRegression();
void polynomialRegression();

int main() {
    int choice;

    while (1) {
        printf("\nChoose the regression method:\n");
        printf("1. Linear Regression\n");
        printf("2. Exponential Regression\n");
        printf("3. Polynomial Regression\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                linearRegression();
                break;
            case 2:
                exponentialRegression();
                break;
            case 3:
                polynomialRegression();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void linearRegression() {
    int n, i;
    float x[10], y[10], sx = 0, sy = 0, sxy = 0, sx2 = 0, a, b;

    printf("\nEnter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x and y:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);

        sx += x[i];
        sy += y[i];
        sxy += x[i] * y[i];
        sx2 += x[i] * x[i];
    }

    b = ((n * sxy) - (sx * sy)) / ((n * sx2) - (sx * sx));
    a = (sy / n) - (b * sx / n);

    printf("Fitted line: y = %.4f + %.4f*x\n", a, b);
}

void exponentialRegression() {
    int n, i;
    float x[10], y[10], sx = 0, slgy = 0, sxy = 0, sx2 = 0, a, b, r;

    printf("\nEnter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x and y:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);

        sx += x[i];
        slgy += log(y[i]);
        sxy += x[i] * log(y[i]);
        sx2 += x[i] * x[i];
    }

    b = ((n * sxy) - (sx * slgy)) / ((n * sx2) - (sx * sx));
    r = (slgy / n) - (b * sx / n);
    a = exp(r);

    printf("Fitted curve: y = %.4fe^(%.4fx)\n", a, b);
}

void polynomialRegression() {
    int n, m, i, j, k;
    float x[20], fx[20], a[20][20], b[20], z[20], sum, pivot, term;

    printf("\nEnter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the degree of polynomial to be fitted: ");
    scanf("%d", &m);

    printf("Enter the values of x and f(x):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("f[%d]: ", i);
        scanf("%f", &fx[i]);
    }

    // Construct the coefficient matrix
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= m; j++) {
            sum = 0;
            for (k = 0; k < n; k++) {
                sum += pow(x[k], i + j);
            }
            a[i][j] = sum;
        }
    }

    // Construct the RHS vector
    for (i = 0; i <= m; i++) {
        sum = 0;
        for (k = 0; k < n; k++) {
            sum += fx[k] * pow(x[k], i);
        }
        b[i] = sum;
    }

    // Forward Elimination
    for (k = 0; k <= m; k++) {
        pivot = a[k][k];
        if (fabs(pivot) < 1e-6) {
            printf("Method failed: zero pivot encountered.\n");
            return;
        }
        for (i = k + 1; i <= m; i++) {
            term = a[i][k] / pivot;
            for (j = 0; j <= m; j++) {
                a[i][j] -= a[k][j] * term;
            }
            b[i] -= b[k] * term;
        }
    }

    // Back Substitution
    for (i = m; i >= 0; i--) {
        sum = 0;
        for (j = i + 1; j <= m; j++) {
            sum += a[i][j] * z[j];
        }
        z[i] = (b[i] - sum) / a[i][i];
    }

    printf("Fitted polynomial: y = %.4f", z[0]);
    for (i = 1; i <= m; i++) {
        printf(" + %.4f*x^%d", z[i], i);
    }
    printf("\n");
}

