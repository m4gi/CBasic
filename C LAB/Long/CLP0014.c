#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MONEY_START 1000
#define MIN_VALUE 1
#define MAX_VALUE 6

int getInt(int, int);
int menu();
int roll(int, int);
void buyChips(int *money, int *chips);
void sellChips(int *money, int *chips);
void playCraps(int *money, int *chips);
void playArupsGameOfDice(int *money, int *chips);
void statusReport(int *money, int *chips);

int main()
{
    int money = MONEY_START;
    int chips = 0;
    int isContinue = 1;
    printf("You have $%d.\n", money);
    do
    {
        int choose = menu();
        switch (choose)
        {
        case 1:
            buyChips(&money, &chips);
            break;
        case 2:
            sellChips(&money, &chips);
            break;
        case 3:
            playCraps(&money, &chips);
            break;
        case 4:
            playArupsGameOfDice(&money, &chips);
            break;
        case 5:
            statusReport(&money, &chips);
            break;
        default:
            printf("GoodBye !\n");
            isContinue = 0;
        }
    } while (isContinue == 1);
}

int getInt(int minValue, int maxValue)
{
    int value;
    char check;

    do
    {
        int rc = scanf("%d%c", &value, &check);
        fflush(stdin);
        if (rc != 2 || check != '\n')
        {
            printf("Invalid value!\n");
        }
        else if (value > maxValue || value < minValue)
        {
            printf("Value out of range!\n");
        }
        else
        {
            return value;
        }
    } while (1);
}

int menu()
{
    int choose;
    printf("Welcome to the Casino. Here are your choices: \n");
    printf("1) Buy chips \n");
    printf("2) Sell chips \n");
    printf("3) Play Craps \n");
    printf("4) Play Arup's Game of Dice \n");
    printf("5) Status Report \n");
    printf("6) Quit \n");

    choose = getInt(MIN_VALUE, MAX_VALUE);
    return choose;
}

void buyChips(int *money, int *chips)
{
    printf("How much cash do you want to spend for chips?\n");
    int cash = getInt(0, 100000);
    if (cash > *money)
    {
        printf("Sorry, you do not have that much money. No chips bought.\n");
    }
    else
    {
        *money -= (cash / 11) * 11;
        *chips += cash / 11;
        printf("You bought %d chips.\n", cash / 11);
    }
}

void sellChips(int *money, int *chips)
{
    printf("How many chips you want to sell?\n");
    int chipSell = getInt(0, 100000);
    if (chipSell > *chips)
    {
        printf("Sorry, you do not have many chips. No chips sold.\n");
    }
    else
    {
        *chips -= chipSell;
        *money += chipSell * 10;
        printf("You sold %d chips.\n", chipSell);
    }
}

void statusReport(int *money, int *chips)
{
    printf("You currently have $%d left and %d chips.\n", *money, *chips);
}

int roll(int minValue, int maxValue)
{
    srand((unsigned)time(NULL));
    return minValue + rand() % (maxValue + 1 - minValue);
}

void playCraps(int *money, int *chips)
{
    printf("How many chips would you like to bet?\n");
    int chipsBet = getInt(0, *chips);
    if (chipsBet == 0)
    {
        printf("Sorry, that is not allowed. No game played.\n");
    }
    else
    {
        *chips -= chipsBet;
        printf("Press 'r' and hit enter for your first roll.\n");
        getchar();
        int rollTwoDice = roll(2, 12);
        printf("You rolled a %d.\n", rollTwoDice);
        if (rollTwoDice == 7 || rollTwoDice == 11)
        {
            printf("You win !\n");
            *chips += chipsBet * 2;
        }
        else if (rollTwoDice == 2 || rollTwoDice == 3 || rollTwoDice == 12)
        {
            printf("You lose !\n");
        }
        else
        {
            int k = rollTwoDice;
            int isStop = 0;
            do
            {
                printf("Press 'r' and hit enter for your next roll.\n");
                getchar();
                int nextRoll = roll(2, 12);
                printf("You rolled a %d.\n", nextRoll);
                if (nextRoll == k)
                {
                    printf("You win!\n");
                    *chips += 2 * chipsBet;
                    isStop = 1;
                }
                else if (nextRoll == 7)
                {
                    printf("Sorry, you have lost.\n");
                    isStop = 1;
                }
            } while (isStop == 0);
        }
    }
}

void playArupsGameOfDice(int *money, int *chips)
{
    printf("How many chips would you like to bet?\n");
    int chipsBet = getInt(0, *chips);
    if (chipsBet == 0)
    {
        printf("Sorry, that is not allowed. No game played.\n");
    }
    else
    {
        *chips -= chipsBet;
        printf("Press 'r' and hit enter for your first roll.\n");
        fflush(stdin);
        getchar();
        int rollTwoDice = roll(2, 12);
        printf("You rolled a %d.\n", rollTwoDice);
        if (rollTwoDice == 11 || rollTwoDice == 12)
        {
            printf("You win !\n");
            *chips += chipsBet * 2;
        }
        else if (rollTwoDice == 2)
        {
            printf("You lose !\n");
        }
        else
        {
            int k = rollTwoDice;
            int point;
            printf("Press 'r' and hit enter for your next roll.\n");
            getchar();
            int nextRoll = roll(2, 12);
            printf("You rolled a %d.\n", nextRoll);
            point = nextRoll;
            if (point > k)
            {
                printf("You win!\n");
                *chips += 2 * chipsBet;
            }
            else
            {
                printf("Sorry, you have lost.\n");
            }
        }
    }
}