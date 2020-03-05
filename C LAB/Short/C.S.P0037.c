#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
int Enter()
{
    int n;
    printf("Check Square Number Program\n");
    printf("Enter a positive number n = ");
    scanf("%d", &n);
    return n;
}
int Checksquare(int n)
{
    int temp = sqrt(n);
    if (temp * temp == n)
        return temp;
    else
        return -1;
}
int main(int argc, char const *argv[])
{
    char c;
    int n, temp;
    do
    {
        n = Enter();
        if (n < 0)
        {
            printf("Please enter a positive integer!\n");
            system("pause");
            printf("\n\n");
        }
        else
        {
            temp = Checksquare(n);
            if (temp > 0)
            {
                printf("%d is a square number %d = %d x %d\n", n, n, temp, temp);
                system("pause");
                printf("\n\n");
            }
            else
            {
                printf("%d is not a square number\n", n);
                system("pause");
                printf("\n\n");
            }
        }
    } while (c != 27);

    return 0;
}
