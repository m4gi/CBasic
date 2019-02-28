#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int a;
    printf("Enter number: ");
    scanf("%d",&a);
    a = (a % 2 == 1) ? printf("Not divisible") : printf("Divisible");
    getch();
    return 0;
}
