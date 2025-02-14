#include<stdio.h>
#include<conio.h>
#include<math.h>

#define f(x) exp(x) // Define the function here

int main() {
    float x0, xn, h, v;
    float fx0, fx1, fx2, fx3;
    printf("Enter Lower & Upper Limits:\n");
    scanf("%f%f", &x0, &xn);
    h = (xn - x0)/3;
    fx0 = f(x0);  // Use the defined function
    fx1 = f(x0 + h);
    fx2 = f(x0 + 2*h);
    fx3 = f(xn);
    v = 3*h/8 * (fx0 + 3*fx1 + 3*fx2 + fx3);
    printf("Integral Value: %.4f\n", v);
    getch();
    return 0;
}