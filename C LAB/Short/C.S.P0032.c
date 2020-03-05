/*Addition of digits in a natural number.*/
#include <stdio.h>
#include <conio.h>
void Calculator()
{
    int n, sum = 0, m;
    printf("Enter an integer n=");
    scanf("%d", &n);
    if(n<0) n*=-1;
    while (n > 0)
    {
        m = n % 10;
        sum = sum + m;
        n = n / 10;
    }
    printf("Sum digit = %d", sum);
}
int main(int argc, char const *argv[])
{
    char c;
    printf("Sum Digit Program\n");
    do
    {
        Calculator();
        printf("\nPress any key to continue.\n");
        fflush(stdin);
        c = getch();
    } while (c != 27);
    return 0;
}
