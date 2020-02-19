#include <stdio.h>
double fraction(int b)
{
    double f = b;
    while (f > 1)
    {
        f = (f / 10);
    }
    return f;
}
int main(int argc, char const *argv[])
{
    int a, b;
    double c;
    printf("enter two number :\n");
    scanf("%d%d", &a, &b);
    if (a >= 0)
        c = (double)(a + fraction(b));
    if (a < 0)
        c = (double)(a - fraction(b));
    printf("%lf", c);
    getch();
    return 0;
}