#include <stdio.h>

unsigned long long fibonaci(int n)
{
    unsigned long t1 = 1, t2 = 1, f = 1, i;
    for (i = 3; i <= n; i++)
    {
        f = t1 + t2;
        t1 = t2;
        t2 = f;
    }
    return f;
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Input number: ");
    scanf("%d", &n);
    printf("\nFibonaci of %d is %lld", n, fibonaci(n));
    getch();
    return 0;
}
