#include <stdio.h>

long fact(int n)
{
    int i;
    long rs, j = 1;
    for (i = 2; i <= n; i++)
    {
        j = j * i;
    }
    rs = j;
    return rs;
}
double sumfact(int n)
{

    double rs, f, i, s = 0;
    for (i = 1; i <= n; i++)
    {
        f = fact(i);
        s += f / i;
    }
    rs = s;
    return rs;
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number:");
    scanf("%d", &n);
    printf("Sum = %f", sumfact(n));
    return 0;
}

