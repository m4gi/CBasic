#include <stdio.h>

double square(int n)
{
    double rs;
    rs = n * n;
    return rs;
}
int main(int argc, char const *argv[])
{
    int num;
    double n;
    printf("Input number:");
    scanf("%d", &num);
    n = square(num);    
    printf("The square of %d is: %.2f \n", num, n);
    getch();
    return 0;
}
