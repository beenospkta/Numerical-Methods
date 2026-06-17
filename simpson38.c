#include <stdio.h>
#include <conio.h>
#include <math.h>

#define f(x) (1.0/(1.0 + (x)*(x)))

int main() {
    float lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;

    printf("Enter lower limit of integration: ");
    scanf("%f", &lower);

    printf("Enter upper limit of integration: ");
    scanf("%f", &upper);

    printf("Enter number of sub intervals (multiple of 3): ");
    scanf("%d", &subInterval);

    if (subInterval % 3 != 0) {
        printf("Error: Number of sub intervals must be a multiple of 3.\n");
        return 1;
    }

    stepSize = (upper - lower) / subInterval;

    integration = f(lower) + f(upper);

    for (i = 1; i <= subInterval - 1; i++) {
        k = lower + i * stepSize;

        if (i % 3 == 0)
            integration += 2 * f(k);
        else
            integration += 3 * f(k);
    }

    integration = integration * 3 * stepSize / 8;

    printf("\nRequired value of integration is: %.6f", integration);

    getch();
    return 0;
}