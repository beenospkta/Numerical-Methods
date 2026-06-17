#include <stdio.h>
#include <math.h>

#define f(x) (1.0 / (1.0 + (x) * (x)))

int main() {
    float lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;

    printf("Enter lower limit of integration: ");
    scanf("%f", &lower);

    printf("Enter upper limit of integration: ");
    scanf("%f", &upper);

    printf("Enter number of sub intervals (even number): ");
    scanf("%d", &subInterval);

    if (subInterval % 2 != 0) {
        printf("Error: Number of sub intervals must be even for Simpson's 1/3 Rule.\n");
        return 1;
    }

    stepSize = (upper - lower) / subInterval;

    integration = f(lower) + f(upper);

    for (i = 1; i < subInterval; i++) {
        k = lower + i * stepSize;

        if (i % 2 == 0)
            integration += 2 * f(k);
        else
            integration += 4 * f(k);
    }

    integration = integration * stepSize / 3.0;

    printf("\nRequired value of integration = %.6f\n", integration);

    return 0;
}