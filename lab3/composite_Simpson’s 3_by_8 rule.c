#include<stdio.h>
#include<conio.h>
#include<math.h>

#define f(x) exp(x)  // Define the function here

int main() {
    float x0, xn, h, v, a;
    int k, i;
    printf("Enter Lower & Upper Limits:\n");
    scanf("%f%f", &x0, &xn);
    printf("Enter Segments (multiple of 3):\n");
    scanf("%d", &k);
    h = (xn - x0)/k;
    v = f(x0) + f(xn);  // Use the defined function
    for(i=1; i<k; i++) {
        a = x0 + i*h;
        v += (i%3 == 0) ? 2*f(a) : 3*f(a);
    }
    v = 3*h/8 * v;
    printf("Integral Value: %.4f\n", v);
    getch();
    return 0;
}