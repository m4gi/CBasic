#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
char filename[30];
char *line_buf = NULL;
char temp[10] = {};
char c;

void loadData(char **ArrWord, int sizeOfArr) //Tải dữ liệu từ file
{
    printf("What file stores the puzzle words?\n");
    fflush(stdin);
    gets(filename);
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        fflush(stdin);
        printf("Can not open file!!!\n");
        getch();
        exit(1);
        return;
    }
    for (int i = 0; i < sizeOfArr; i++)
    {
        fgets(ArrWord[i], 30, f);
        if (i < sizeOfArr - 1)
            ArrWord[i][strlen(ArrWord[i]) - 1] = '\0';
    }
    free(line_buf);
    line_buf = NULL;
    fclose(f);
}
char upcase(char *c)
{
    strupr(c);
    return *c;
}
int Choice(char choice[])
{
    char isTrue[10] = "yes";
    printf("\nWould you like to play hangman (yes/no)?\n");
    fflush(stdin);
    gets(choice);
    if (strcmp(choice, isTrue) == 0)
    {
        return TRUE;
    }
    else if (strcmp(choice, "no") == 0)
    {
        printf("Thanks for playing!!\n");
        return FALSE;
    }
}
void gameStart(char string[])
{
    int i, correct, incorrect;
    int n = strlen(string);
    incorrect = 0;
    correct = 0;
    char guess;
    int state;
    printf("\n%s\n", string);
    memset(temp, '_', sizeof(temp));
    while (strcmp(string, temp) != 0 && incorrect != 5)
    {
        state = FALSE;
        printf("Your currently %d incorrect guesses\n", incorrect);
        printf("Here is your puzzle\n");
        for (i = 0; i < n; i++)
        {
            printf("%c ", temp[i]);
        }
        if (correct == n)
        {
            printf("\nCongratuation!You got the correct word, %s\n", string);
            break;
        }
        printf("\nPlease enter your guess. \n");
        fflush(stdin);
        guess = getch();
        printf("%c\n", upcase(&guess));
        printf("\n");

        for (i = 0; i < n; i++)
        {
            if ((guess == string[i]) && (guess != temp[i]))
            {
                temp[i] = string[i];
                state = 1;
            }
        }
        if (state == TRUE && (strcmp(string, temp) != 0))
        {
            printf("Congratulation! You guess the letter in the puzzle.\n");
            correct++;
        }
        if (state == FALSE)
        {
            int count = 0;
            for (i = 0; i < n; i++)
            {
                if ((guess != string[i]))
                {
                    count++;
                }
            }
            if (count == n)
            {
                printf("Sorry! That letter NOT in the puzzle.\n");
                incorrect++;
            }
            else
            {
                printf("Sorry! your have guessed the letter already.\n");
                printf("Now as count it a miss\n");
                incorrect++;
            }
            printf("\n");
        }
    }
}
void getString(char **ArrWord, int sizeOfArr)
{
    int i;
    char choice[10] = "";
    char String[10] = {};
    memset(String, '_', sizeof(String));
    srand((int) time(0));
    i = rand() % sizeOfArr;
    strcpy(String, ArrWord[i]);
    gameStart(String);
}

int main(int argc, char const *argv[])
{
    char **ArrWord = NULL;
    int sizeOfArr = 18;
    char choice[10] = "";
    ArrWord = (char **)malloc(sizeOfArr * sizeof(char *));
    for (int i = 0; i < sizeOfArr; i++)
        ArrWord[i] = (char *)malloc(30 * sizeof(char));
    loadData(ArrWord, sizeOfArr);
    while (Choice(choice))
    {
        fflush(stdin);
        getString(ArrWord, sizeOfArr);
    } 
    getch();
    return 0;
}
