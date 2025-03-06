#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define F2(x) (6*x) // Define the second-order differential equation d2y/dx2 = 6x

float f1(float x, float y, float z)
{
    return z; // dy/dx = z
}

float f2(float x, float y, float z)
{
    return F2(x); // d2y/dx2 = 6x
}

float shoot(float x0, float y0, float z0, float xn, float h, int p)
{
    float x = x0, y = y0, z = z0, k1, k2, y1, z1;

    do
    {
        k1 = h * f1(x, y, z);
        k2 = h * f2(x, y, z);
        y1 = y + k1;
        z1 = z + k2;
        x = x + h;
        y = y1;
        z = z1;

        if (p == 1)
        {
            printf("%f\t%f\n", x, y);
        }
    } while (x < xn);

    return y;
}

int main()
{
    float x0, y0, xn, yn, h, m1, m2, m3, b, b1, b2, b3, e;
    int p = 0;

    printf("Enter initial value x0: ");
    scanf("%f", &x0);
    printf("Enter initial value y0: ");
    scanf("%f", &y0);
    printf("Enter final value xn: ");
    scanf("%f", &xn);
    printf("Enter final value yn: ");
    scanf("%f", &yn);
    printf("Enter step size h: ");
    scanf("%f", &h);

    printf("Enter Trial M1: ");
    scanf("%f", &m1);
    b = yn;
    b1 = shoot(x0, y0, m1, xn, h, 1);

    if (fabs(b1 - b) < 0.00005)
    {
        printf("\nSolution:\n");
        shoot(x0, y0, m1, xn, h, 1);
        return 0;
    }
    else
    {
        printf("\nEnter Trial M2: ");
        scanf("%f", &m2);
        b2 = shoot(x0, y0, m2, xn, h, 1);
    }

    do
    {
        m3 = m2 + (m2 - m1) * (b - b2) / (b2 - b1);
        if (fabs(b2 - b1) < 0.00005)
        {
            printf("Error: Division by zero or too small difference\n");
            exit(0);
        }
        b3 = shoot(x0, y0, m3, xn, h, 0);

        if (fabs(b3 - b) < 0.00005)
        {
            printf("\nSolution:\n");
            shoot(x0, y0, m3, xn, h, 1);
            break;
        }

        m1 = m2;
        m2 = m3;
        b1 = b2;
        b2 = b3;

    } while (1);

    return 0;
}