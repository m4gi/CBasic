#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
char *filename = "Money.txt";
void displayTheGame(float moneyLeft)
{
    printf("You have $%.2f. \n", moneyLeft);
    printf("Choose one of following option:\n");
    printf("1. Play the slot machine.\n");
    printf("2. Save game!\n");
    printf("3. Crash out!\n");
}
int generateRandomNumber()
{
    srand(time(0));
    int numberOne = rand() % 10;
    int numberTwo = rand() % 10;
    int numberThree = rand() % 10;
    printf("The Slot machine shows %c%c%c.\n", '0' + numberOne, '0' + numberTwo, '0' + numberThree);
    if (numberOne == numberTwo && numberTwo == numberThree)
    {
        return (3);
    }
    else if (numberOne == numberTwo || numberTwo == numberThree || numberOne == numberThree)
    {
        return (2);
    }
    return (1);
}
float returnMoney(float *moneyLeft)
{
    FILE *fp = fopen(filename, "r");
    fscanf(fp, "%f", moneyLeft);
    fclose(fp);
    return (*moneyLeft);
}
void displayOptionOne(float *moneyLeft)
{
    int result = generateRandomNumber();
    if (result == 3)
    {
        printf("You win big prize, $10.00!\n");
        *moneyLeft += 10;
    }
    else if (result == 2)
    {
        printf("You win 50 cent\n");
        *moneyLeft += 0.5;
    }
    else
    {
        printf("Sorry you don't win anything\n");
    }
}
void displayOptionTwo(float *moneyLeft)
{
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "%f", *moneyLeft);
    printf("Your money had saved \n");
    fclose(fp);
}
void displayOptionThree(float *moneyLeft)
{
    printf("Thank you for playing! You and with $%.2f!\n", *moneyLeft);
}
int getInt(char *mess, char *error, int min, int max)
{
    int num, k = 1;
    char c;
    do
    {
        printf("%s", mess);
        k = scanf("%d%c", &num, &c);
        if (k == 0 || c != '\n' || num <= min || num >= max)
        {
            printf("%s\n", error);
            fflush(stdin);
            k = 0;
        }
    } while (k == 0);
    return (num);
}
int main(int argc, char const *argv[])
{
    int choice;
    float moneyLeft = 10;
    displayOptionTwo(&moneyLeft);
    moneyLeft = returnMoney(&moneyLeft);
    do
    {
        displayTheGame(moneyLeft);
        choice = getInt("Enter your choice:", "Invalid Input!\n", 0, 4);
        switch (choice)
        {
        case 1:
            displayOptionOne(&moneyLeft);
            moneyLeft = moneyLeft - 0.25;
            break;
        case 2:
            displayOptionTwo(&moneyLeft);
            break;
        case 3:
            displayOptionThree(&moneyLeft);
            getch();
            exit(0);
            break;
        default:
            printf("Invalid Option!\n");
        }
    } while (moneyLeft > 0);
    printf(">>>>>>>>Good Bye!!!<<<<<<<<");
    getch();
    return 0;
}