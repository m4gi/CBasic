#include <stdio.h>
#include <conio.h>
#include <string.h>

void InputSize(int *size, char List[][30])
{
    do
    {
        printf("Enter the value of n\n");
        scanf("%d", &(*size));
    } while ((*size) <= 0);
    printf("\nEnter %d name\n", (*size));
    for (int i = 0; i < (*size); i++)
    {
        fflush(stdin);
        gets(List[i]);
    }
}
void swap(char a[], char b[])
{
    char tmp[30];
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
}

void Output(int size, char List[][30])
{
    for (int i = 0; i < size; i++)
        printf("%d. %s\n", i + 1, List[i]);
}

void Sort(int size, char List[][30])
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1; j++)
            if (strcmp(List[j + 1], List[j]) < 0)
                swap(List[j], List[j + 1]);
}
int main(int argc, char const *argv[])
{
    int size;
    char List[100][30];
    InputSize(&size, List);
    printf("\nList input name:\n");
    Output(size, List);
    printf("\nList Sort Name:\n");
    Sort(size, List);
    Output(size, List);
    getch();
    return 0;
}
