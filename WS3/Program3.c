#include <stdio.h>
#include <conio.h>

int getr(double x, double y, double r)
{
    double d2 = x * x + y * y;
    double r2 = r * r;
    if (d2 < r2)
        return 1;
    else if (d2 == r2)
        return 0;
    return -1;
}
int main(int argc, char const *argv[])
{
    double x, y, r;
    printf("Input co-ordinate(x,y): ");
    scanf("%lf%lf", &x, &y);
    do
    {
        printf("Input Radius: ");
        scanf("%lf", &r);
        if (r <= 0)
            printf("Input a positive Radius!!!\n");

    } while (r <= 0);
    if (getr(x, y, r) == 1)
        printf("The point is in the circle\n");
    else if (getr(x, y, r) == 0)
        printf("The point is on the circle\n");
    else
        printf("The point is out the circle\n");
    getch();
    return 0;
}
