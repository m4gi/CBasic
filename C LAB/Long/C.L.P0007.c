#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void makeCode(int secretCode[4])
{
    int i, randColor;
    for (i = 0; i < 4; i++)
    {
        randColor = rand() % 6; //creates a number
        secretCode[i] = randColor;
    }
}
void guess(int guessCode[4])
{
    printf("\nEnter your guess:\n");
    for (int i = 0; i < 4; i++)
        scanf("%d", &guessCode[i]);
}
void codeCheck(int secretCode[4], int guessCode[4], int *blackPeg, int *whitePeg)
{
    int i, j, checkSecret[4] = {1, 1, 1, 1}, checkGuess[4] = {1, 1, 1, 1};
    *blackPeg = *whitePeg = 0;

    for (i = 0; i < 4; i++) //if secret and guess's position and color are same, blackpeg increases and mark "check"
        if (secretCode[i] == guessCode[i])
        {
            ++*blackPeg;
            checkSecret[i] = checkGuess[i] = 0;
        }

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if ((secretCode[i] == guessCode[j]) && checkGuess[i] && checkSecret[j] && i != j)
            { // determines crushes and eliminates extra whitePegs
                ++*whitePeg;
                checkSecret[j] = checkGuess[i] = 0;
            }
}
void displayGuess(int guessCode[4], int blackPeg, int whitePeg)
{
    int i;
    printf("\nYou have %d perfect matches and %d imperfect matches.\n", blackPeg, whitePeg);
}
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int i, turn, blackPeg, whitePeg, wrongGuess;
    int secretCode[4], guessCode[4];
    char c;
    clock_t t1, t2;
    do
    {
        turn = 0;
        t1 = clock();
        system("cls");
        printf("\033[1;31m");
        printf("Welcome to MasterMind!!!\n\n");
        printf("At each turn you will enter your guess for the playing board.\n");
        printf("A valid guess ahs 4 values in between 0 and 5.\n");
        printf("Each guess will have each number within the guess separated by a space.\n");
        printf("When you are ready, enter your first guess.\n");
        printf("After this messeage, you should guess again. You have 10 chances, good luck!\n");
        makeCode(secretCode);
        for (wrongGuess = 1; wrongGuess <= 10; wrongGuess++) //gives 10 rights to guess
        {
            guess(guessCode);
            codeCheck(secretCode, guessCode, &blackPeg, &whitePeg);
            displayGuess(guessCode, blackPeg, whitePeg);
            turn++;
            if (blackPeg == 4) //if player guess correct all, than the game finishes
            {
                t1 = clock() - t1;
                printf("\nYou have won the game in %02d turns and %02d:%02d!!!\n", turn, (t1 / CLOCKS_PER_SEC) / 60, (t1 / CLOCKS_PER_SEC) % 60);
                break;
            }
        }
        if (wrongGuess == 11) //if player cannot guess correct colors in 10 rounds, you losts
            printf("\nSorry, you have exceeded the maximum number of turns. You lose.\nHere is the winning board: %d %d %d %d\n\n", secretCode[0], secretCode[1], secretCode[2], secretCode[3]);
        printf("\nPress enter to continue another , ESC to exit\n");
        fflush(stdin);
        c = getch();
    } while (c != 27);
    return 0;
}
