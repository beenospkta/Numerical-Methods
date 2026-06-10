// Fitting in c program Y = ae^bx
#include<stdio.h>
#include<conio.h>
#include<math.h>

#define S 50

int main(){
    int n, i;
    float x[20], y[20],Y[20], sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0, a, b, A;
    printf("C programs for Exponiantial Curve Fitting\n");
    printf("\n Enter the value of number of terms n:");
    scanf("%d", &n);
    printf("Enter the values of x: \n");
    for(i=1; i<=n-1; i++){

        scanf("%f", &x[i]);
    }

    printf("\n Enter the values of y: ");
    for(i=1; i<=n-1; i++){

        scanf("%f", &y[i]);
    }

    for (i=1; i<=n-1; i++){
        sumX = sumX + x[i];
        sumX2 = sumX2 + x[i]*x[i];
        sumY = sumY + y[i];
        sumXY = sumXY + x[i]*y[i];
    }

    A = ((sumX2*sumY-sumX)*1.0/(n*sumX2-sumX*sumX)*1.0);
    b = ((n*sumXY-sumX*sumY)*1.0/(n*sumX2-sumX*sumX)/1.0);

    a = exp(A);

    printf("The curve is Y = %4.3fe^%4.3fX", a, b);
    getch();
    return(0);
}