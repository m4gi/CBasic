#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x,y;
    float f,f1;
    double d,d1;
    printf("Enter first integer number:");
    scanf("%d", &x);
    printf("Enter second integer number:");
    scanf("%d", &y);
    printf("Enter first float number:");
    scanf("%f", &f);
    printf("Enter sencond foat number:");
    scanf("%f", &f1);
    printf("Enter first double number:");
    scanf("%lf", &d);
    printf("Enter sencond double number:");
    scanf("%lf", &d1);
    printf("Variable x is at address: %u, value: %d, size: %d \n", &x, x, sizeof(x));
    printf("Variable y is at address: %u, value: %d, size: %d \n", &y, y, sizeof(y));
    printf("Variable f is at address: %u, value: %f, size: %d \n", &f, f, sizeof(f));
    printf("Variable f1 is at address: %u, value: %f, size: %d \n", &f1, f1, sizeof(f1));
    printf("Variable d is at address: %u, value: %lf, size: %d \n", &d, d, sizeof(d));
    printf("Variable d1 is at address: %u, value: %lf, size: %d \n", &d1, d1, sizeof(d1));
    getch();
    return 0;
}
