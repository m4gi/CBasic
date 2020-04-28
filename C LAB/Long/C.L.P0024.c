#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct DATA
{
    char Word[200];
    char Meaning[400];

} DATA;
DATA List[100];
int WordRank = 0;
int MeaningRank = 0;
void AddWord();
int Count();
void EditWord();
int FindWord(char[200]);
void Lookup();
void PrintToData();
void PrintToTitle();
void Token(char[]);
int uChoice()
{
    int choice;
    printf("1. Create a new word\n");
    printf("2. Edit a word\n");
    printf("3. Look up meaning\n");
    printf("4. Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main(int argc, char const *argv[])
{
    int Choice;
    char Word[200];
    char Meaning[400];
    FILE *ft, *fd;
    ft = fopen("title.txt", "r+");
    fd = fopen("data.txt", "r+");
    if (ft == NULL || fd == NULL)
    {
        perror("Error: ");
    }
    else
    {
        while (fgets(Word, 200, ft) != NULL)
        {
            Token(Word);
            strncpy(List[WordRank].Word, Word, 200);
            WordRank++;
        }
        while (fgets(Meaning, 400, fd) != NULL)
        {
            Token(Meaning);
            strncpy(List[MeaningRank].Meaning, Meaning, 400);
            MeaningRank++;
        }
        printf("\nLoad Data Successful!!!");
    }
    fclose(ft);
    fclose(fd);
    do
    {
        Choice = uChoice();
        switch (Choice)
        {
        case 1:
            AddWord();
            PrintToTitle();
            PrintToData();
            break;
        case 2:
            EditWord();
            break;
        case 3:
            Lookup();
            break;
        case 4:
            return 0;
        }
    } while (Choice >= 1 && Choice <= 4);
    getch();
    return 0;
}
void Token(char c[])
{
    int len = strlen(c);
    if (c[len - 1] == '\n')
    {
        c[len - 1] = '\0';
    }
}

int Count()
{
    if (WordRank > MeaningRank)
    {
        return MeaningRank;
    }
    else
        return WordRank;
}

void AddWord()
{
    fflush(stdin);
    printf("\nEnter a new Word: ");
    gets(List[WordRank].Word);
    WordRank++;
    printf("\nEnter Meanings: ");
    gets(List[MeaningRank].Meaning);
    MeaningRank++;
}

int FindWord(char Word[200])
{
    int i;
    for (i = 0; i < Count(); i++)
    {
        if (strcmp(List[i].Word, Word) == 0)
            return i;
    }
    return -1;
}

void PrintToTitle()
{
    FILE *ft = fopen("title.txt", "w+");
    int i;
    for (i = 0; i < WordRank; i++)
    {
        fprintf(ft, "%s\n", List[i].Word);
    }
    fclose(ft);
}

void PrintToData()
{
    FILE *fd = fopen("data.txt", "w+");
    int i;
    for (i = 0; i < MeaningRank; i++)
    {
        fprintf(fd, "%s\n", List[i].Meaning);
    }
    fclose(fd);
}
void EditWord()
{
    char Word[200];
    char Meaning[400];
    fflush(stdin);
    printf("\nEnter Word that you need to edit: ");
    gets(Word);
    Token(Word);
    int pos = FindWord(Word);
    if (pos >= 0)
    {
        printf("\nEnter new Meaning: ");
        gets(Meaning);
        Token(Meaning);
        strncpy(List[pos].Meaning, Meaning, 400);
        PrintToData();
    }
    else
        printf("\nThis Word does't exist in file!");
}
void Lookup()
{
    int pos;
    char Word[200];
    char Meaning[400];
    fflush(stdin);
    printf("\nEnter Word that you need to know: ");
    gets(Word);
    pos = FindWord(Word);
    if (pos >= 0)
    {
        printf("\nMeaning: %s", List[pos].Meaning);
    }
    else
        printf("\nThis key does't belong to database!");
}