#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, x, y, z;

    printf("nhap x: ");
    scanf("%lf", &x);
    printf("nhap y: ");
    scanf("%lf", &y);
    printf("nhap z: ");
    scanf("%lf", &z);
    a = log(abs(y - sqrt(abs(x))) * (x - (y / (z + pow(x, 0.5)))));
    b = x - (pow(x, 2) / gt(3)) + (pow(x, 5) / gt(5));
    printf("\na= %.5lf ", a);
    printf("\nb= %.5lf", b);
    getch();
    return 0;
}
int gt(int t)
{
    if (t == 1)
        return 1;
    return t * gt(t - 1);
}