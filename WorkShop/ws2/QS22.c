#include <stdio.h>

int gt(int n)
{
    int s = 1;
    for (int i = 1; i <= n; i++)
        s *= i;
    return s;
}

void strong(int n)
{
    int s = 0;
    int m = n;
    while (n != 0)
    {
        s += gt(n % 10);
        n = n / 10;
    }
    if (m == s)
        printf("%d is a strong number", m);
    else
        printf("%d is not a strong number", m);
}

int main(int argc, char const *argv[])
{
    int n;
    printf("enter a number:");
    scanf("%d", &n);
    strong(n);
    return 0;
}
