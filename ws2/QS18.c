#include <stdio.h>

int fibonaci(int n)
{
    if ((n == 1) || (n == 2))
        return 1;
    else
        return fibonaci(n - 1) + fibonaci(n - 2);
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    int i = 1;
    printf("Here is the Fibonacci series upto  to %d terms : \n", n);
    while (i != n)
    {
        printf("%3d", fibonaci(i));
        i++;
    }
    return 0;
}
