#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    float a[3][3], x[3], y[3];
    float lambda_old = 0, lambda_new;
    float e, error;
    int i, j, count = 1;

    printf("Enter the 3x3 matrix:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter initial vector (3 elements):\n");
    for(i = 0; i < 3; i++)
    {
        scanf("%f", &x[i]);
    }

    printf("Enter tolerable error: ");
    scanf("%f", &e);

    printf("\nIter\tEigenvalue\n");

    do
    {
        for(i = 0; i < 3; i++)
        {
            y[i] = 0;
            for(j = 0; j < 3; j++)
            {
                y[i] += a[i][j] * x[j];
            }
        }

        lambda_new = fabs(y[0]);
        for(i = 1; i < 3; i++)
        {
            if(fabs(y[i]) > lambda_new)
                lambda_new = fabs(y[i]);
        }

        for(i = 0; i < 3; i++)
        {
            x[i] = y[i] / lambda_new;
        }

        error = fabs(lambda_new - lambda_old);

        printf("%d\t%.6f\n", count, lambda_new);

        lambda_old = lambda_new;
        count++;

    } while(error > e);

    printf("\nDominant Eigenvalue = %.6f\n", lambda_new);

    printf("Corresponding Eigenvector:\n");
    for(i = 0; i < 3; i++)
    {
        printf("%.6f\n", x[i]);
    }

    getch();
    return 0;
}