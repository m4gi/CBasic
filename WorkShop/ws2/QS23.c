#include <stdio.h>
int gt(int n)
{
    int s = 1;
    for (int i = 1; i <= n; i++)
        s *= i;
    return s;
}
int strong(int n)
{
    int s = 0;
    int m = n;
    while (n != 0)
    {
        s += gt(n % 10);
        n = n / 10;
    }
    if (m == s)
        return 1;
}

int main()
{
    int a, b;
    printf("starting a range:");
    scanf("%d", &a);
    printf("ending a range:");
    scanf("%d", &b);
    printf("the strong number from %d to %d:", a, b);
    for (int i = a; i <= b; i++)
        if (strong(i) == 1)
            printf("%6d", i);

    return 0;
}
