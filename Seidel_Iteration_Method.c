#include <stdio.h>
#include <conio.h>
#include <math.h>

#define f1(x, y, z) ((17 - y + 2 * z) / 20.0)
#define f2(x, y, z) ((-18 - 3 * x + z) / 20.0)
#define f3(x, y, z) ((25 - 2 * x + 3 * y) / 20.0)

int main()
{
    float x0 = 0, y0 = 0, z0 = 0;
    float x1, y1, z1;
    float e1, e2, e3, e;
    int count = 1;

    printf("Enter tolerable error: ");
    scanf("%f", &e);

    printf("\nCount\t x\t\t y\t\t z\n");

    do
    {
        x1 = f1(x0, y0, z0);
        y1 = f2(x1, y0, z0);
        z1 = f3(x1, y1, z0);

        printf("%d\t %.4f\t %.4f\t %.4f\n",
               count, x1, y1, z1);

        e1 = fabs(x1 - x0);
        e2 = fabs(y1 - y0);
        e3 = fabs(z1 - z0);

        x0 = x1;
        y0 = y1;
        z0 = z1;

        count++;

    } while (e1 > e || e2 > e || e3 > e);

    printf("\nSolution:\n");
    printf("x = %.4f\n", x1);
    printf("y = %.4f\n", y1);
    printf("z = %.4f\n", z1);

    getch();
    return 0;
}