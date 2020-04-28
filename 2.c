#include <stdio.h>
#include <string.h>
#include <time.h>

using namespace std;

class Account
{
public:
    Account()
    {
    }
    char account[15];
    char pin[7];
    char accName[10];
    double balances;
    char moneyType[6];
};

bool checkValid(char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] < 48 || s[i] > 57)
            return false;
    }
    return true;
}

int registerID()
{
    //char title[4][20] = {"Account", "Name", "Balances", "MoneyType"};
    //char title1[2][20] = {"Account", "Pin"};

    FILE *registerAcc;
    FILE *accInfo;
    registerAcc = fopen("account.txt", "a");
    accInfo = fopen("accInfo.txt", "a");
    //fprintf(accInfo, "%-20s%-15s%-22s%-11s\n",title[0],title[1],title[2],title[3]);
    //fprintf(registerAcc,"%-20s%-7s\n", title1[0], title1[1]);

    if (!registerAcc)
        return 1;
    if (!accInfo)
        return 1;
    Account mrname;
    printf("Enter your first name: ");
    scanf("%s", &mrname.accName);
    printf("name: %s\n", mrname.accName);
    printf("Enter your Account code(14 numbers): ");
    scanf("%s", &mrname.account);

    printf("Enter your Account pin(6 numbers): ");
    scanf("%s", &mrname.pin);

    printf("Enter your Account Money type (USD or VND): ");
    scanf("%s", &mrname.moneyType);

    printf("Enter your Account balances: ");
    char balances[22];
    scanf("%s", &balances);
    sscanf(balances, "%lf", &mrname.balances);
    fprintf(registerAcc, "%-20s%-7s\n", mrname.account, mrname.pin);
    fprintf(accInfo, "%-20s%-15s%-22.3lf%-11s\n", mrname.account, mrname.accName, mrname.balances, mrname.moneyType);
    fclose(registerAcc);
    fclose(accInfo);
}
int countUser()
{
    int length = 0;
    FILE *count;
    char buf[1000];
    count = fopen("account.txt", "r");
    while (fgets(buf, 1000, count) != NULL)
    {
        length += 1;
    }
    fclose(count);
    return length;
}
int getUser(char logCode[])
{
    char logPin[7];
    printf("Account Code: ");
    scanf("%s", &logCode);
    printf("PIN: ");
    scanf("%s", &logPin);
    char tempCode[15];
    char tempPin[7];
    FILE *login;
    login = fopen("account.txt", "r");
    if (!login)
        return 0;
    while (fscanf(login, "%s%s", &tempCode, &tempPin) == 2)
    {
        if (strcmp(logCode, tempCode) == 0 && strcmp(logPin, tempPin) == 0)
        {
            fclose(login);
            return 1;
        }
    }
    fclose(login);
    return 0;
}

void currTime(char s[])
{
#include <stdio.h> /* puts, printf */
#include <time.h>  /* time_t, struct tm, time, localtime */

    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strcpy(s, asctime(timeinfo));
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
    fprintf(paste, "%-20s%-15s%-22s%-11s\n", title[0], title[1], title[2], title[3]);
    while (fscanf(copy, "&s&s&f&s", &tempAccount, &tempName, &tempBalances, &tempMoneyType) == 4)
    {
        if (strcpy(logCode, tempAccount) != 0)
            fprintf(paste, "%-20s%-15s%-22.3lf%-11s\n", tempAccount, tempName, tempBalances, tempMoneyType);
        else
            fprintf(paste, "%-20s%-15s%-22.3lf%-11s\n", tempAccount, tempName, balances, tempMoneyType);
    }
    fclose(copy);
    fclose(paste);
    remove("accInfo.txt");
    rename("newInfo", "accInfo.txt");
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
    fprintf(saveWithdraw, "%-15s%-22lf%-11s%-28s\n", title[0], title[1], title[2], title[3]);
    while (fscanf(readTrans, "&s&s&lf&s", &tempAccount, &tempName, &tempBalances, &tempMoneyType) == 4)
    {
        if (strcpy(logCode, tempAccount) == 0)
        {
            if (amount > tempBalances)
            {
                fclose(saveWithdraw);
                fclose(readTrans);
                printf("Not enough money to withdraw!\n");
            }
            else
                fprintf(saveWithdraw, "%-20s%-15s%-22lf%-11s%-29s\n", tempAccount, tempName, amount, tempMoneyType, time);
        }
    }

    fclose(saveWithdraw);
    fclose(readTrans);
    update(logCode, tempBalances - amount);
}

void transferTrans(double amount, char dest[], char logCode[])
{
    char tempName[15];
    char tempAccount[20];
    double tempBalances;
    char tempMoneyType[11];
    char time[28];
    char title[8][20] = {"AccountSrc", "NameSrc", "AccountDest", "NameDest", "Amount", "MoneyType", "Time"};
    currTime(time);
    FILE *transfer;
    FILE *readTrans;
    transfer = fopen("transfer.txt", "a");
    readTrans = fopen("accInfo.txt", "r");
    fprintf(transfer, "%-20s%-15%-20s%-15s%-22lf%-11s%-28s\n", title[0], title[1], title[2], title[3], title[4], title[5], title[6]);
    while (fscanf(readTrans, "%s%s%lf%s", &tempName, &tempAccount, &tempBalances, &tempMoneyType) == 4)
    {
    }
}

int main()
{

    int tc;
    int n;
    do
    {
        printf("1. Login\n");
        printf("2. Register new ATM card\n");
        printf("3. Exit\n");
        printf("Choose (1-3): ");
        scanf("%d%c", &tc, &n);
        if (tc == 1)
        {
            char logCode[20];
            if (getUser(logCode))
            {
                printf("ACCESS GRANTED!!\n");
                int tc1;
                do
                {

                    int n1;
                    printf("1. Withdaw\n");
                    printf("2. Transfer\n");
                    printf("3. Exit\n");
                    printf("Choose (1-3): ");
                    scanf("%d%c", &tc1, &n1);
                    if (tc1 == 1)
                    {
                    }
                    if (tc1 == 2)
                    {
                    }
                } while (tc1 != 3);
            }
            else
                printf("ACCESS DENIED!!\n");
        }

        else if (tc == 2)
        {
            char u[] = "user";
            char str[3];
            int th = countUser();
            //sprintf(str,"%d",th);

            //strcpy(user[th], strcat(u,str));
            //Account user[th];
            registerID();
        }
    } while (tc != 3);
}
