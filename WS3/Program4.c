#include <stdio.h>

long long fact(long n)
{
    long long i, p = 1;
    for (i = 2; i <= n; i++)
    {
        p *= i;
    }
    return p;
}
int main(int argc, char const *argv[])
{
    long n;
    do
    {
        printf("Input number: ");
        scanf("%ld", &n);
        if(n<=0) printf("Positive Integer!!!\n");
    } while(n<=0);
    printf("Factorial of %ld is %lld.\n", n, fact(n));
    getch();
    return 0;
}
