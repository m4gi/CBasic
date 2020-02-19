#include <stdio.h>
int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
        return a;
    }
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main(int argc, char const *argv[])
{
    int a, b;
    do
    {
        printf("Input a,b: ");
        scanf("%d%d", &a, &b);
    } while (a <= 0 || b <= 0);
    printf("GCD(%d,%d) = %d\n", a, b, gcd(a,b));
    printf("LCM(%d,%d) = %d\n", a, b, lcm(a,b));
    getch();
    return 0;
}
