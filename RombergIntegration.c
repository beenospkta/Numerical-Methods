#include <stdio.h>
#include <math.h>

#define f(x) (1.0 / (x))

int main() {
    float x0, xn, t[10][10];
    float h, sm, sl, a;
    int i, k, p, q, c, m;

    printf("Enter lower and upper limit: ");
    scanf("%f%f", &x0, &xn);

    printf("Enter p and q required T(p,q): ");
    scanf("%d%d", &p, &q);

    h = xn - x0;

    /* First trapezoidal estimate */
    t[0][0] = (h / 2.0) * (f(x0) + f(xn));

    /* Compute first column of Romberg table */
    for (i = 1; i <= p; i++) {
        sl = pow(2, i - 1);
        sm = 0.0;

        for (k = 1; k <= sl; k++) {
            a = x0 + (2 * k - 1) * h / pow(2, i);
            sm += f(a);
        }

        t[i][0] = t[i - 1][0] / 2.0 + sm * h / pow(2, i);
    }

    /* Romberg extrapolation */
    for (c = 1; c <= p; c++) {
        for (k = 1; k <= c && k <= q; k++) {
            m = c - k;

            t[m + k][k] =
                (pow(4, k) * t[m + k][k - 1] -
                 t[m + k - 1][k - 1]) /
                (pow(4, k) - 1);
        }
    }

    printf("\nRomberg estimate of integration = %.6f\n", t[p][q]);

    return 0;
}