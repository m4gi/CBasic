#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define MAX 1000
typedef struct DATA
{
    char Account[15];
    char PIN[7];
    char AccName[20];
    double Balances;
    char Type[4];
} DATA;
DATA ATM[MAX];
int n = 0;
void LoadData()
{
    FILE *fr = fopen("account.txt", "r");
    FILE *fi = fopen("accInfo.txt", "r");
    char tempName[15];
    char tempAccount[20];
    double tempBalances;
    char tempMoneyType[11];
    int check = 0;
    if (fr == NULL)
    {
        fflush(stdin);
        printf("Can not open file \"account.txt\"!!!\n");
        return;
    }
    if (fi == NULL)
    {
        fflush(stdin);
        printf("Can not open file \"accInfo.txt\" !!!\n");
        return;
    }
    do
    {
        if (check == 1)
        {
            n++;
        }
        fscanf(fr, "%s %s\n", ATM[n].Account, ATM[n].PIN);
        check = 0;
        do
        {
            fscanf(fi, "%s %s %lf %s\n", tempAccount, tempName, &tempBalances, tempMoneyType);
            if (strcmp(tempAccount, ATM[n].Account) == 0)
            {
                check = 1;
                strcpy(ATM[n].AccName, tempName);
                ATM[n].Balances = tempBalances;
                strcpy(ATM[n].Type, tempMoneyType);
                break;
            }
        } while (!feof(fi));

    } while (!feof(fr));
    fclose(fr);
    fclose(fi);
}
void Register()
{
    FILE *fr = fopen("account.txt", "a");
    FILE *fi = fopen("accInfo.txt", "a");
    if (fr == NULL)
    {
        fflush(stdin);
        printf("Can not open file \"account.txt\"!!!\n");
        return;
    }
    if (fi == NULL)
    {
        fflush(stdin);
        printf("Can not open file \"accInfo.txt\" !!!\n");
        return;
    }
    n++;
    printf("Enter your first name: ");
    fflush(stdin);
    gets(ATM[n].AccName);
    printf("Enter your Account code (14 Digits) : ");
    fflush(stdin);
    gets(ATM[n].Account);
    printf("Enter your Account PIN (6 Digits) : ");
    fflush(stdin);
    gets(ATM[n].PIN);
    printf("Enter your Account Money type (VND/USD): ");
    fflush(stdin);
    gets(ATM[n].Type);
    printf("Enter your Account Balances: ");
    scanf("%lf", &ATM[n].Balances);
    fprintf(fr, "%-15s %-7s\n", ATM[n].Account, ATM[n].PIN);
    fprintf(fi, "%-15s %-15s %-15.3lf %-10s\n", ATM[n].Account, ATM[n].AccName, ATM[n].Balances, ATM[n].Type);
    fclose(fr);
    fclose(fi);
}
void currTime(char s[])
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strcpy(s, asctime(timeinfo));
}

int getUser(char logCode[])
{
    char logPin[7];
    printf("Account Code: ");
    scanf("%s", logCode);
    printf("PIN: ");
    scanf("%s", logPin);
    for (int i = 0; i <= n; i++)
    {
        if ((strcmp(logCode, ATM[i].Account) == 0) && (strcmp(logPin, ATM[i].PIN) == 0))
        {
            printf("Your account has: %.3lf\n", ATM[i].Balances);
            return 1;
        }
    }
    return 0;
}

void update(char logCode[], double balances)
{
    char tempName[15];
    char tempAccount[20];
    double tempBalances;
    char tempMoneyType[11];
    char title[4][20] = {"Account", "Name", "Balances", "MoneyType"};
    FILE *copy;
    FILE *paste;
    copy = fopen("accInfo.txt", "r");
    paste = fopen("newInfo.txt", "w");
    while (fscanf(copy, "%s %s %lf %s", tempAccount, tempName, &tempBalances, tempMoneyType) == 4)
    {
        if (strcmp(logCode, tempAccount) != 0)
            fprintf(paste, "%-20s %-15s %-22.3lf %-11s\n", tempAccount, tempName, tempBalances, tempMoneyType);
        else
            fprintf(paste, "%-20s %-15s %-22.3lf %-11s\n", tempAccount, tempName, balances, tempMoneyType);
    }
    fclose(copy);
    fclose(paste);
    remove("accInfo.txt");
    rename("newInfo.txt", "accInfo.txt");
}

void withdrawTrans(char logCode[], double amount)
{
    char tempName[15];
    char tempAccount[20];
    double tempBalances;
    char tempMoneyType[11];
    char title[5][20] = {"Account", "Name", "Amount", "MoneyType", "Time"};
    char time[28];
    currTime(time);
    FILE *saveWithdraw;
    FILE *readTrans;
    saveWithdraw = fopen("withdraw.txt", "a");
    readTrans = fopen("accInfo.txt", "r");
    while (fscanf(readTrans, "%s %s %lf %s", tempAccount, tempName, &tempBalances, tempMoneyType) == 4)
    {
        if (strcmp(logCode, tempAccount) == 0)
        {
            if (amount > tempBalances)
            {
                fclose(saveWithdraw);
                fclose(readTrans);
                printf("Not enough money to withdraw!\n");
                return;
            }
            else
            {
                printf("Draw Money successful!!\n");
                fprintf(saveWithdraw, "%-20s %-15s %-22.3lf %-11s %-29s\n", tempAccount, tempName, amount, tempMoneyType, time);
            }
        }
    }
    fclose(readTrans);
    fclose(saveWithdraw);
    update(logCode, tempBalances - amount);
}

void transferTrans(double amount, char dest[], char logCode[])
{
    char tempName[15];
    char tempAccount[20];
    double tempBalances;
    char tempMoneyType[11];
    char time[28];
    currTime(time);
    FILE *transfer;
    FILE *readTrans;
    char tempName1[15];
    char tempAccount1[20];
    double tempBalances1;
    transfer = fopen("transfer.txt", "a");
    readTrans = fopen("accInfo.txt", "r");
    while (fscanf(readTrans, "%s %s %lf %s", tempAccount, tempName, &tempBalances, tempMoneyType) == 4)
    {
        if (strcmp(logCode, tempAccount) == 0)
        {
            if (amount > tempBalances)
            {
                fclose(transfer);
                fclose(readTrans);
                printf("Not enough money to transfer!\n");
                return;
            }
            else
            {
                printf("Transfer money successful!!\n");
                fprintf(transfer, "%-20s %-15s %-20s %-15s %-22lf %-11s %-28s\n", tempAccount, tempName, tempAccount1, tempName1, tempBalances, tempMoneyType, time);
            }
        }
    }
    fclose(transfer);
    fclose(readTrans);
    update(logCode, tempBalances - amount);
    update(dest, tempBalances1 + amount);
}
void DrawMoney(char logCode[])
{
    double amount;
    printf("Enter your money want to draw : ");
    scanf("%lf", &amount);
    withdrawTrans(logCode, amount);
}
void TransferMoney(char logCode[])
{
    char dest[15];
    double amount;
    printf("Enter your money want to transfer : ");
    scanf("%lf", &amount);
    printf("Enter dest Account Code: ");
    fflush(stdin);
    gets(dest);
    transferTrans(amount, dest, logCode);
}
void Login()
{
    char logCode[15];
    if (getUser(logCode))
    {
        printf("ACCESS GRANTED!!\n");
        int Ops;
        do
        {
            printf("1. Withdaw Money\n");
            printf("2. Transfer Money\n");
            printf("3. Exit\n");
            printf("Choose (1-3): ");
            scanf("%d", &Ops);
            if (Ops == 1)
            {
                DrawMoney(logCode);
            }
            if (Ops == 2)
            {
                TransferMoney(logCode);
            }
        } while (Ops != 3);
    }
    else
        printf("ACCESS DENIED!!\n");
}
int uChoice()
{
    int choice;
    printf("\n>>>>>>>>>>>Automated Teller Machine<<<<<<<<<<\n");
    printf("\n 1- Login.");
    printf("\n 2- Register New Account.");
    printf("\n 3- Quit.");
    printf("\nEnter your choice:  ");
    scanf("%d", &choice);
    return choice;
}

int main(int argc, char const *argv[])
{
    LoadData();
    int choice;
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            Login();
            break;
        case 2:
            Register();
            break;
        }
    } while (choice >= 1 && choice <= 2);
    return 0;
}
