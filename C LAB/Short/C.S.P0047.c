#include <stdio.h>
#include <conio.h>
#include <string.h>

void AddStudent(char ArrStudent[][30], int size)
{
    if (size < 100)
    {
        printf("Enter new student name: ");
        fflush(stdin);
        gets(ArrStudent[size]);
        printf("Student has been added to list successfully!\n");
    }
    else
    {
        printf("The list has full.It cannot add a new student.\n");
    }
}
void RemoveStudent(char ArrStudent[][30], int size)
{
    char name[30];
    int Available = 0;
    int pos;
    printf("Please enter student name to remove: ");
    fflush(stdin);
    gets(name);
    for (int i = 0; i < size; i++)
    {
        if (strcmp(ArrStudent[i], name) == 0)
        {
            Available = 1;
            pos = i;
            for (int j = pos; j < size - 1; j++)
            {
                strcpy(ArrStudent[j], ArrStudent[j + 1]);
            }
        }
    }
    if (Available == 1)
    {
        printf("Student name has been removed from list successfully!\n");
    }
    else
    {
        printf("Student name doesn't exist in list.\n");
    }
}
void SearchStudent(char ArrStudent[][30], int size)
{
    char name[30];
    int Available = 0;
    int pos;
    printf("Please enter student name to search: ");
    fflush(stdin);
    gets(name);
    for (int i = 0; i < size; i++)
    {
        if (strcmp(ArrStudent[i], name) == 0)
        {
            Available = 1;
            printf("The position of student name in list is %d.\n", i);
        }
    }
    if (Available == 0)
        printf("The studnet name don't have in list.\n");
}
void swap(char a[], char b[])
{
    char tmp[30];
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
}
void SortStudent(char AddStudent[][30], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (strcmp(AddStudent[j], AddStudent[j + 1]) > 0)
                swap(AddStudent[j], AddStudent[j + 1]);
}
void Display(char ArrStudent[][30], int size)
{
    printf("Total student: %d\n", size);
    if (size > 0)
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d. %s\n", i + 1, ArrStudent[i]);
        }
    }
}
int uChoice()
{
    int choice;
    printf("\n=================MENU================\n");
    printf("\n 1- Add a student.");
    printf("\n 2- Remove a student.");
    printf("\n 3- Search a student.");
    printf("\n 4- Print list student in an accending folder.");
    printf("\n 5- Exit.");
    printf("\nInput [1..5]:  ");
    scanf("%d", &choice);
    return choice;
}
int main(int argc, char const *argv[])
{
    char ArrStudent[100][30];
    int size = 0;
    int choice;
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            AddStudent(ArrStudent, size);
            size++;
            break;
        case 2:
            RemoveStudent(ArrStudent, size);
            size--;
            break;
        case 3:
            SearchStudent(ArrStudent, size);
            break;
        case 4:
            SortStudent(ArrStudent, size);
            Display(ArrStudent, size);
            break;
        default:
            printf("\nPress any key to exit!!!");
        }
    } while (choice >= 1 && choice <= 4);
    getch();
    return 0;
}
