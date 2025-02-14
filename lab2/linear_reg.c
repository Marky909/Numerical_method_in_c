#include <stdio.h>

int n;
float sx = 0, sy = 0, sx2 = 0, sxy = 0;

int main() {
    printf("Enter the number of elements in the data set: ");
    scanf("%d", &n);
    
    int x[n], y[n];

    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%d", &x[i]);
        printf("y[%d] = ", i);
        scanf("%d", &y[i]);
    }

    // Display the elements entered by the user 
    for (int i = 0; i < n; i++) {
        printf("\n\tx[%d] = %d", i, x[i]);
        printf("\n\ty[%d] = %d", i, y[i]);
    }

    // Finding the summations of the data 
    for (int i = 0; i < n; i++) {
         sx += x[i];
         sy += y[i];
         sx2 += x[i] * x[i];
         sxy += x[i] * y[i];
    }

    printf("\n\nThe value of sx: %.2f", sx);
    printf("\nThe value of sy: %.2f", sy);
    printf("\nThe value of sx2: %.2f", sx2);
    printf("\nThe value of sxy: %.2f\n", sxy);

    // Computing the value of the coefficients 
    float b = ((float)n * sxy - sx * sy) / ((float)n * sx2 - sx * sx);
    float a = (sy / (float)n) - b * (sx / (float)n);

    printf("The regression coefficients are b = %.2f and a = %.2f\n", b, a);
    printf("After fitting\n");
    printf("y = %.2f + %.2fx", a, b);

    return 0;
}
