#include <stdio.h>
#include <stdlib.h>
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
void chardata()
{
    printf("\n===============Character data==============\n");
    char s[2];
    int a, b;
    printf("Input: ");
    scanf("%s", s);
    a = s[0];
    b = s[1];
    int i, j;
    i = a;
    j = b;
    if (i < j)
    {

        for (i; i <= j; i++)
        {
            printf("%c: %d %xh\n", i, i, i);
        }
    }
    else
    {

        for (i; i >= j; i--)
        {
            printf("%c: %d %xh\n", i, i, i);
        }
    }
}
int uChoice()
{
    int choice;
    printf("\n=================MENU================\n");
    printf("\n Press 1. Processing date data.");
    printf("\n Press 2. Character data.");
    printf("\n Press 3. Quit!!!\n");
    printf("\n=====================================\n");
    printf("\nInput [1..3]:  ");
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
            checkday();
            break;
        case 2:
            chardata();
            break;
        case 3:
            system("pause");
            exit(1);
            break;
        default:
            printf("Input number 1->3.");
        }
    } while (choice >= 1 && choice <= 2);
    getch();
    return 0;
}