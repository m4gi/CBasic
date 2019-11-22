#include <stdio.h>

int NT(int n)
{
    int i;
    if (n < 2)
        return 0;
    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void prime()
{
    int n;
    printf("\n=============Prime Number============\n");
    printf("Enter a number: ");
    scanf("%d", &n);
    if (NT(n))
        printf("This is a prime number.\n");
    else
        printf("This is not a prime number\n.");
}
void minmax()
{
    int a, b, max;
    printf("\n=============Min Max============\n");
    printf("Input number: ");
    scanf("%d", &a);
    printf("Input number: ");
    scanf("%d", &b);
    max = a > b ? a : b;
    printf("\n Max digits: %d", max);
}

int uChoice()
{
    int choice;
    printf("\n=============Menu============\n");
    printf("\n 1. Prime number.");
    printf("\n 2. Min max.");
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
            prime();
            break;
        case 2:
            minmax();
            break;
        default:
            printf("Input number 1->3.");
        }
    } while (choice >= 1 && choice <= 2);
    getch();
    return 0;
}