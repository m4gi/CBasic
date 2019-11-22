
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    double a, b;
    double *p1, *p2;
    p1 = &a;
    p2 = &b;

    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter a again: ");
    scanf("%lf", p1);
    printf("Enter b: ");
    scanf("%lf", p2);

    double *p3;
    p3 = (double *)malloc(sizeof(double));
    printf("Enter p3: ");
    scanf("%lf", p3);
    double rs = *p1 + *p2 + *p3;
    double rs1 = a + b + *p3;
    printf("\n result 1 is %lf", rs);
    printf("\n result 2 is %lf", rs1);
    getch();
    return 0;
}
