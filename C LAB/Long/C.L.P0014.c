#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void buyChips(int *money, int *chips)
{
    int cash;
    printf("How much cash do you want to spend for chips?\n");
    scanf("%d", &cash);
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
void sellChips(int *money, int *chip)
{
    int sell;
    printf("How much chips do you want to sell?\n");
    scanf("%d", &sell);
    if (sell > *chip)
    {
        printf("Sorry, you do not have that many chips. No chips sold.\n");
    }
    else
    {
        *money += sell * 10;
        *chip -= sell;
        printf("You sold %d chips.\n", sell);
    }
}
int roll(int minValue, int maxValue)
{
    srand((unsigned)time(NULL));
    return minValue + rand() % (maxValue + 1 - minValue);
}
void playCraps(int *money, int *chip)
{
    int bet;
    printf("How many chips would you like to bet?\n");
    scanf("%d", &bet);
    if (bet > *chip || bet == 0)
    {
        printf("Sorry, that is not allowed. No game played.\n");
    }
    else
    {
        *chip -= bet;
        printf("Press 'r' and hit enter for your first roll.\n");
        fflush(stdin);
        getchar();
        int rollrandom = roll(2, 12);
        printf("You rolled a %d.\n", rollrandom);
        if (rollrandom == 7 || rollrandom == 12)
        {
            printf("You win\n");
            *chip += bet * 2;
        }
        else if (rollrandom == 2 || rollrandom == 3 || rollrandom == 12)
        {
            printf("You lose !\n");
        }
        else
        {
            int k = rollrandom;
            int isStop = 0;
            do
            {
                printf("Press 'r' and hit enter for your next roll.\n");
                fflush(stdin);
                getchar();
                int nextRoll = roll(2, 12);
                printf("You rolled a %d.\n", nextRoll);
                if (nextRoll == k)
                {
                    printf("You win!\n");
                    *chip += 2 * bet;
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
void playArups(int *money, int *chip)
{
    int bet;
    printf("How many chips would you like to bet?\n");
    scanf("%d", &bet);
    if (bet > *chip || bet == 0)
    {
        printf("Sorry, that is not allowed. No game played.\n");
    }
    else
    {
        *chip -= bet;
        printf("Press 'r' and hit enter for your first roll.\n");
        fflush(stdin);
        getchar();
        int rollrandom = roll(2, 12);
        printf("You rolled a %d.\n", rollrandom);
        if (rollrandom == 11 || rollrandom == 12)
        {
            printf("You win !\n");
            *chip += bet * 2;
        }
        else if (rollrandom == 2)
        {
            printf("You lose !\n");
        }
        else
        {
            int k = rollrandom;
            int point;
            printf("Press 'r' and hit enter for your next roll.\n");
            getchar();
            int nextRoll = roll(2, 12);
            printf("You rolled a %d.\n", nextRoll);
            point = nextRoll;
            if (point > k)
            {
                printf("You win!\n");
                *chip += 2 * bet;
            }
            else
            {
                printf("Sorry, you have lost.\n");
            }
        }
    }
}
void statusReport(int *money, int *chip)
{
    printf("You currently have $%d left and %d chips\n", *money, *chip);
}
void quitGame(int *money, int *chip)
{
    *money += *chip * 10;
    *chip = 0;
    printf("After selling your chíp, you have $%d. Thanks for playing!\n", *money);
    getch();
    exit(1);
}
int uChoice()
{
    int choice;
    printf("\nWelcome to the Casino. Here are your choice:\n");
    printf("\n 1- Buy chips.");
    printf("\n 2- Sell chips.");
    printf("\n 3- Play Craps.");
    printf("\n 4- Play Arup's Game of Dice.");
    printf("\n 5- Status Report.");
    printf("\n 6- Quit.");
    printf("\nInput [1..6]:  ");
    do
    {
        scanf("%d", &choice);
        if (choice < 1 || choice > 6)
            printf("\nInvalid value!!!\nPlease enter 1 - 6 : ");
    } while (choice < 1 || choice > 6);

    return choice;
}
int main(int argc, char const *argv[])
{
    int choice;
    int chip = 0, money = 1000;

    printf("\nYou have %d", money);
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            buyChips(&money, &chip);
            break;
        case 2:
            sellChips(&money, &chip);
            break;
        case 3:
            playCraps(&money, &chip);
            break;
        case 4:
            playArups(&money, &chip);
            break;
        case 5:
            statusReport(&money, &chip);
            break;
        case 6:
            quitGame(&money, &chip);
            break;
        }
    } while (choice >= 1 && choice <= 6);
    getch();
    return 0;
}