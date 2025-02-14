#include<stdio.h>
#include<conio.h>

#define f(x) x*x*x+2 // Define the function here

int main() {
    float x0, x1, h, fx0, fx1, v;
    printf("Enter Lower & Upper Limits:\n");
    scanf("%f%f", &x0, &x1);
    h = x1 - x0;
    fx0 = f(x0);  // Use the defined function
    fx1 = f(x1);
    v = h/2 * (fx0 + fx1);
    printf("Integral Value: %.4f\n", v);
    getch();
    return 0;
}