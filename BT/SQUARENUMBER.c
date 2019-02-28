#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int n,a,b;
    printf("Enter number: ");
    scanf("%d", &n);
    b = sqrt(n);
    a = n % b;
    if (a == 0)
        printf("%d x %d",b,b);
    else
        printf("False");
    getch();
    return 0;
}
