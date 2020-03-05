#include <stdio.h>
#include <conio.h>
#include <math.h>

void QuadraticEuqation()
{
    int a, b, c, delta;
    double x1, x2;
    printf("\nQuadratic Euqation: ax^2 + bx + c = 0\n");
    do
    {
        printf("\tInput a: ");
        scanf("%d", &a);
        if (a == 0)
            printf("Input a different 0 !!!\n");
    } while (a == 0);
    printf("\tInput b: ");
    scanf("%d", &b);
    printf("\tInput c: ");
    scanf("%d", &c);
    delta = ((pow(b, 2)) - (4 * a * c));
    if (delta < 0)
    {
        printf("\nThe equation has no solution.\n");
    }
    else if (delta == 0)
    {
        x1 = x2 = (-b) / (2 * a);
        printf("\nThe equation has 2 dual solutions x1=x2= %d\n", x1);
    }
    else
    {
        x1 = (((-b) + sqrt(delta))) / (2 * a);
        x2 = (((-b) - sqrt(delta))) / (2 * a);
        printf("\nThe equation has 2 solutions\n");
        printf("\tx1 = %lf\n", x1);
        printf("\tx2 = %lf\n", x2);
    }
}
void BankDeposit()
{
    printf("\n BankDeposit: \n");
    printf("==============================\n");
    double deposit, rate, amount;
    int month, check;
    printf("\nInput your deposit, monthly rate and the number of months: ");
    fflush(stdin);
    check = scanf("%lf%*c%lf%*c%d", &deposit, &rate, &month);
    if (check != 3)
        printf("Retype 3 value please !!\n");
    else
    {
        if (deposit <= 0)
        {
            printf("Invalid deposit, try agian!!!\n");
            do
            {
                printf("Input deposit: ");
                scanf("%lf", &deposit);
            } while (deposit <= 0);
        }
        if (month < 0)
        {
            printf("The number of months must be positive!\n");
            do
            {
                printf("Input month: ");
                scanf("%d", &month);
            } while (month < 0);
        }
        if (rate <= 0 || rate > 1)
        {
            printf("Monthly rate must be positive but less than or equal to 0.1!\n");
            do
            {
                printf("Input rate: ");
                scanf("%lf", &rate);
            } while (rate <= 0 || rate > 1);
        }
    }
    amount = (float)(deposit * (pow(1+rate,month)));
    printf("Your amount after duration: %f \n", amount);
}
int uChoice()
{
    int choice;
    printf("\n=================MENU================\n");
    printf("\n1 - Quadratic Euqation.");
    printf("\n2 - Bank Deposit");
    printf("\n3 - Quit!!!\n");
    printf("\nEnter your Choice: ");
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
            QuadraticEuqation();
            break;
        case 2:
            BankDeposit();
            break;
        }
    } while (choice >= 1 && choice <= 2);
    getch();
    return 0;
}