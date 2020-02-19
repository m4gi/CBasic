#include <stdio.h>
int fibonaci(int n)
{
    if ((n == 1) || (n == 2))
        return 1;
    else
        return fibonaci(n - 1) + fibonaci(n - 2);
}
void fibo()
{
    int n;
    printf("\n=============Fibonacci sequence============\n");
    printf("Enter number: ");
    scanf("%d", &n);
    int i = 1;
    printf("Here is the Fibonacci series upto  to %d terms : \n", n);
    while (i != n)
    {
        printf("%3d", fibonaci(i));
        i++;
    }
}
int valid(int d, int m, int y)
{
    int maxd = 31;
    if (d < 1 || d > 31 || m < 1 || m > 12)
        return 0;
    if (m == 4 || m == 6 || m == 9 || m == 11)
        maxd = 30;
    else if (m == 2)
    {
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
            maxd = 29;
    }
    else
        maxd = 28;
    return d <= maxd;
}
void checkday()
{
    int d, m, y;
    printf("\n=============Check a date============\n");
    printf("Enter day, month, year: ");
    scanf("%d %d %d", &d, &m, &y);
    if (valid(d, m, y) != 0)
    {
        printf("Valid day");
    }
    else
    {
        printf("Invalid day");
    }
}

int uChoice()
{
    int choice;
    printf("\n=============Menu============\n");
    printf("\n 1. Fibonacci sequence.");
    printf("\n 2. Check a date.");
    printf("\n 3. Quit!!!\n");
    printf("\nInput [1..3]: ");
    scanf("%d", &choice);
    return choice;
}
int main(int argc, char const *argv[])
{
    int choice;
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            fibo();
            break;
        case 2:
            checkday();
            break;
        default:
            printf("Input number 1->3.");
        }
    } while (choice >= 1 && choice <= 2);
    getch();
    return 0;
}