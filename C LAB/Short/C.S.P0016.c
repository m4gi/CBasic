/*
Printing Payments and Calculating Total Expenditure.
*/
#include <stdio.h>
#include <conio.h>
void calculate(float mortgage, float year, float payment)
{
    int month = 1;
    float temp;
    printf("Month\tPayment\tAmount Owed\n");
    do
    {
        temp = mortgage * year / 1200;
        mortgage += temp - payment;
        printf("%d\t%.2f\t%.2f\n", month, payment, mortgage);
        month++;
    } while (payment < mortgage);
    printf("%d\t%.2f\t0\n", month, mortgage);
}
int main(int argc, char const *argv[])
{
    float mortgage, payment, year;
    printf("What is the value left on the mortgage?\n");
    scanf("%f", &mortgage);
    printf("What is the annual interest rate of the loan, in percent?\n");
    scanf("%f", &year);
    printf("What is the monthly payment?\n");
    scanf("%f", &payment);
    calculate(mortgage, year, payment);
    getch();
    return 0;
}
