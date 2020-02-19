
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int n,crt;
    printf("enter number:");
    scanf("%d", &n);
    crt = pow(n, 3);
    printf("The cube of %d is %d", n, crt);
    return 0;
}
