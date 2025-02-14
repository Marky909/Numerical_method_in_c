#include<stdio.h>
#include<conio.h>
#include<math.h>

#define f(x) sqrt(1+x*x)  // Define the function here

int main() {
    float x0, xn, h, v, a;
    int k, i;
    printf("Enter Lower & Upper Limits:\n");
    scanf("%f%f", &x0, &xn);
    printf("Enter Number of Segments (even):\n");
    scanf("%d", &k);
    h = (xn - x0)/k;
    v = f(x0) + f(xn);  // Use the defined function
    for(i=1; i<k; i++) {
        a = x0 + i*h;
        v += (i%2 == 0) ? 2*f(a) : 4*f(a);
    }
    v = h/3 * v;
    printf("Integral Value: %.4f\n", v);
    getch();
    return 0;
}