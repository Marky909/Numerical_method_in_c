#include<stdio.h>
#include<conio.h>
#include<math.h>

#define f(x) sqrt(1+x*x)  // Define the function here

int main() {
    float x0, xn, h, v;
    float fx0, fx1, fx2;
    printf("Enter Lower & Upper Limits:\n");
    scanf("%f%f", &x0, &xn);
    h = (xn - x0)/2;
    fx0 = f(x0);  // Use the defined function
    fx1 = f(x0 + h);
    fx2 = f(xn);
    v = h/3 * (fx0 + 4*fx1 + fx2);
    printf("Integral Value: %.4f\n", v);
    getch();
    return 0;
}