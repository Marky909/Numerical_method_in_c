#include<stdio.h>
#include<math.h>

int main(){
    float a[10], b[10], c[10], x0, x1 = 0, tmp, acc = 0.001, f, g;
    int n, i;

    // Taking inputs from the user
    printf("Enter degree (n) of polynomial: ");
    scanf("%d", &n);

    for(i = n; i >= 0; i--) {
        printf("Enter coefficient x[%d]: ", i);
        scanf("%f", &a[i]);
    }

    printf("Enter initial guess: ");
    scanf("%f", &x0);

    // Bairstow's method for finding one root
    do {
        tmp = x1;

        for(i = n; i >= 0; i--) {
            if(i == n) {
                b[i] = a[i];
                c[i] = b[i];
            } else {
                b[i] = a[i] + x0 * b[i + 1];
                c[i] = b[i] + x0 * c[i + 1];
                if(i == 0) {
                    f = b[i];
                }
                if(i == 1) {
                    g = c[i];
                }
            }
        }

        x1 = x0 - f / g;
        x0 = x1;

    } while(fabs(tmp - x1) >= acc);

    // Output the result
    printf("\nOne of the roots is %.4f\n", x1);

    return 0;
}

