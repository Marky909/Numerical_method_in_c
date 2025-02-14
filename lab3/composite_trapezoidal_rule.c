#include <stdio.h>

#define f(x) x*x*x+2  // Define the function here

int main() {
    float x0, xn, h, term, I, a;
    int k, i;
    printf("Enter Lower & Upper Limits:\n");
    scanf("%f%f", &x0, &xn);
    printf("Enter Number of Segments:\n");
    scanf("%d", &k);
    h = (xn - x0) / k;
    term = f(x0) + f(xn);  // Use the defined function
    for (i = 1; i < k; i++) {
        a = x0 + i * h;
        term += 2 * f(a);
    }
    I = h / 2 * term;
    printf("Integral Value: %.4f\n", I);
    getchar();  // Use getchar() instead of getch() for modern compilers
    return 0;
}
