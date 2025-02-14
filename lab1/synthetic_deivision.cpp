#include <stdio.h>

void synthetic_division(int poly[], int n, int d) {
    int i, q[n], r = poly[0];

    for (i = 1; i <= n; i++) {
        q[i - 1] = r;
        r = (r * d) + poly[i];
    }

    printf("Quotient: ");
    for (i = 0; i < n; i++) {
        printf("%d ", q[i]);
    }
    printf("\nRemainder: %d\n", r);
}

int main() {
    int n, i, d, poly[10]; // Fixed-size array for coefficients

    printf("Enter the degree of the polynomial (max 9): ");
    scanf("%d", &n);

    if (n >= 10) {
        printf("Error: Degree exceeds the allowed maximum (9).\n");
        return 1;
    }

    for (i = n; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &poly[n - i]);
    }

    printf("Enter divisor value: ");
    scanf("%d", &d);

    synthetic_division(poly, n, d);

    return 0;
}

