#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char id, name;
    int custid, conu;
    float chg, surchg = 0, gramt, netamt;
    char connm[25];

    printf("Input Customer ID :");
    fflush(stdin);
    scanf("%c", &id);
    printf("Input the name of the customer :");
    fflush(stdin);
    scanf("%s", &name);
    printf("Input the unit consumed by the customer : ");
    scanf("%d", &conu);
    if (conu < 200)
        chg = 1.2;
    else if (conu < 400)
        chg = 1.50;
    else if (conu < 600)
        chg = 1.8;
    else if (conu >= 600)
        chg = 2.00;
    gramt = conu * chg;
    if (gramt > 300)
        surchg = gramt * 0.15;
    netamt = gramt + surchg;
    if (netamt < 100)
        netamt = 100;
    printf("\nElectricity Bill\n");
    printf("Customer ID:%c", id);
    printf("Customer Name:%c", name);
    printf("unit Consumed:%d", conu);
    printf("Amount Charges @Rs. %4.2f per unit :%8.2f\n", chg, gramt);
    printf("Surchage Amount");
    printf("Net Amount Paid By the Customer :%8.2f\n", netamt);
    return 0;
}
