#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
char *filename = "Student.txt";
int pos = 0;

typedef struct DATA
{
    char ID[10];
    char Name[30];
    char Birth[15];
    float Point;

} DATA;
DATA List[20];
void LoadData(char filename[])
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        fflush(stdin);
        printf("Can not open file!!!\n");
        return;
    }
    for (int i = 0; i < MAX; i++)
    {
        fscanf(f, "%s\n", List[i].ID);
        fscanf(f, "%[^\n]s\n", List[i].Name);
        fscanf(f, "%s\n", List[i].Birth);
        fscanf(f, "%f\n", &List[i].Point);
        if (List[i].Point == 0 || List[i].Name == NULL)
        {
            pos = i;
            break;
        }
    }
    printf("List %s found %d student\n", filename, pos);
    fclose(f);
}
void WriteData(char filename[])
{
    FILE *f = fopen(filename, "w+");
    if (f == NULL)
    {
        fflush(stdin);
        printf("Can not open file!!!\n");
        return;
    }
    for (int i = 0; i < pos; i++)
    {
        fprintf(f, "%s\n", List[i].ID);
        fprintf(f, "%s\n", List[i].Name);
        fprintf(f, "%s\n", List[i].Birth);
        fprintf(f, "%.2f\n", List[i].Point);
    }
    fclose(f);
}
void EnterStudent()
{
    char c;
    do
    {
        printf("Enter new student:\n");
        printf("Student code: ");
        fflush(stdin);
        gets(List[pos].ID);
        printf("Student name: ");
        fflush(stdin);
        gets(List[pos].Name);
        printf("Date of birth: ");
        fflush(stdin);
        gets(List[pos].Birth);
        printf("Learning point: ");
        scanf("%f", &List[pos].Point);
        printf("\n-------------------------------------------\nPress enter to continue, Esc to return the main menu.\n");
        pos++;
        fflush(stdin);
        c = getch();
    } while (c != 27);
}
int Trim(char s[], char st[])
{
    char *key;
    char word[10][30];
    int count = 0;

    key = strtok(s, " \t");
    while (key != NULL)
    {
        strcpy(word[count++], key);
        key = strtok(NULL, " \t");
    }
    for (int i = --count; i >= 0; i--)
    {
        if (strcmp(word[i], st) == 0)
        {
            return 1;
        }
    }
    return 0;
}
void Search()
{
    char c;
    do
    {
        char s[10], st[30];
        int count = 0;
        printf("Please enter student name: ");
        fflush(stdin);
        gets(s);
        printf("\n----------------------------------\n");
        for (int i = 0; i <= pos; i++)
        {
            strcpy(st, List[i].Name);
            if (Trim(st, s) == 1)
            {
                count++;
                printf("Student code: %s\nStudent name: %s\nDate of birth: %s\nLearning point: %.2f\n", List[i].ID, List[i].Name, List[i].Birth, List[i].Point);
            }
        }
        if (count == 0)
        {
            printf("No student found in list\n");
        }
        else
        {
            printf("Found %d studen name %s in list", count, s);
        }
        printf("\n-------------------------------------------\nPress enter to continue, Esc to return the main menu.\n");
        fflush(stdin);
        c = getch();
    } while (c != 27);
}
void Sort()
{
    DATA tg;
    for (int i = 0; i < pos - 1; i++)
    {
        for (int j = i + 1; j < pos; j++)
        {
            if (strcmp(List[i].ID, List[j].ID) > 0)
            {

                tg = List[i];
                List[i] = List[j];
                List[j] = tg;
            }
        }
    }
}
void Display()
{
    Sort();
    printf("\nStudent list:");
    printf("\n---------------------------\n");
    for (int i = 0; i < pos; i++)
    {
        printf("\nStudent code: %s\nStudent name: %s\nDate of birth: %s\nLearning point: %.2f\n", List[i].ID, List[i].Name, List[i].Birth, List[i].Point);
        printf("\n----------------------------\n");
    }
}
int uChoice()
{
    int choice;
    printf("\n=================MENU================\n");
    printf("\n 1- Enter Student List.");
    printf("\n 2- Look up student.");
    printf("\n 3- Display student list.");
    printf("\n 4- Exit.");
    printf("\nInput [1..4]:  ");
    scanf("%d", &choice);
    return choice;
}
int main(int argc, char const *argv[])
{
    int choice;
    LoadData(filename);
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            EnterStudent();
            break;
        case 2:
            Search();
            break;
        case 3:
            Display();
            WriteData(filename);
            break;
        case 4:
            printf("\nGood bye!!!");
            WriteData(filename);
            getch();
            exit(1);
        default:
            WriteData(filename);
        }
    } while (choice >= 1 && choice <= 4);
    getch();
    return 0;
}
