#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

int n;
typedef struct DATA
{
    char kind[3];
    int point;
    char ques[200];
    char answer[200];
    int numofchoices;
    char choicelist[100][200];
} DATA;
DATA List[MAX];
void LoadData(char filename[])
{
    printf("What is name of file stores your questions?\n");
    fflush(stdin);
    gets(filename);
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        fflush(stdin);
        printf("Can not open file!!!\n");
        return;
    }
    fscanf(f, "%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%s %d\n%[^\n]\n", List[i].kind, &List[i].point, List[i].ques);
        if (strcmp(List[i].kind, "MC") == 0)
        {
            fscanf(f, "%d\n", &List[i].numofchoices);
            for (int j = 0; j < List[i].numofchoices; j++)
            {
                fscanf(f, "%[^\n]\n", List[i].choicelist[j]);
            }
        }
        fscanf(f, "%[^\n]\n", List[i].answer);
    }
    fclose(f);
}
void PrintQues()
{
    int random, nq, userPoint = 0;
    char userAnswer[200];
    printf("How many questions would you like (out of %d)?\n", n);
    do
    {
        scanf("%d", &nq);
        if (nq > n)
        {
            printf("Sorry, that is too many.\n");
        }
        else if (nq < 1)
            printf("That not valid\n");
    } while (nq < 1 || nq > n);

    srand((unsigned)time(NULL));

    for (int i = 0; i < n; i++)
    {
        random = rand() % nq;
        printf("%s\n%s\n", List[random].kind, List[random].ques);

        if (strcmp(List[random].kind, "MC") == 0)
        {
            for (int j = 0; j < List[random].numofchoices; j++)
            {
                printf("%c) %s\n", (char)(65 + j), List[random].choicelist[j]);
            }
        }
        printf("Your answer: \n");
        fflush(stdin);
        gets(userAnswer);
        if (strcmp(userAnswer, List[random].answer) == 0)
        {
            printf("Correct Answer is %s\n", List[random].answer);
            userPoint = userPoint + List[random].point;
        }
        else if (strcmp(userAnswer, "SKIP") == 0)
        {
            printf("You skipped\n");
            userPoint = userPoint - List[random].point;
            continue;
        }
        else
        {
            userPoint = userPoint - List[random].point;
        }

        printf("Your point is: %d\n", userPoint);
    }
}
int main(int argc, char const *argv[])
{
    char filename[30];
    char FName[30], LName[30];
    printf("What is your first name?\n");
    fflush(stdin);
    gets(FName);
    printf("What is your last name?\n");
    fflush(stdin);
    gets(LName);
    LoadData(filename);
    PrintQues();
    getch();
    return 0;
}
