#include <stdio.h>
int check(int n)
{
    if (n % 2 == 0)
        return 1;
    else
        return 0;
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Input number: ");
    scanf("%d", &n);
    if(check(n))
    {
        printf("The entered number is even");
    }   else printf("The entered number is odd");
    getch();
    return 0;
}
