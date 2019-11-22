#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define arr_size 100
int data;
int a[arr_size];
void myInformation()
{
    char name[50];
    char class[10];
    printf("Enter your name: ");
    fflush(stdin);
    scanf("%[^\n]", &name);
    printf("Enter your class: ");
    fflush(stdin);
    scanf("%[^\n]", &class);
    printf("Your name is: %s in class %s", name, class);
}
void enterArray()
{
    int n, i = 0;
    printf("Enter number of array: ");
    scanf("%d", &n);
    for (i; i < n; i++)
    {
        printf("Enter number A[%d] = ", i);
        scanf("%d", &a[i]);
    }
    data = i;
}
void disArray()
{
    int i;
    printf("\n-----------Display Array----------\n");
    for (int i = 0; i < data; i++)
    {
        printf("%d\t", a[i]);
    }
}
int findX(int d)
{
    int n;
    for (int i = 0; i < data; i++)
    {
        if (a[i] == d)
        {
            n = i;
            break;
        }
        else
            n = -1;
    }
    return n;
}
int chknege()
{
    for (int i = 0; i < data; i++)
    {
        if (a[i] < 0)
            return 1;
        else
            return -1;
    }
}
int uChoice()
{
    int choice;
    printf("\n=================MENU================\n");
    printf("\n Press 1. Enter information of student.");
    printf("\n Press 2. Enter an integer array.");
    printf("\n Press 3. Display an integer array.");
    printf("\n Press 4. Find X value in array.");
    printf("\n Press 5. Check array has an negative or not.");
    printf("\nPress Other.  Exit!!");
    printf("\n=====================================\n");
    printf("\nEnter number: ");
    scanf("%d", &choice);
    return choice;
}
int main(int argc, char const *argv[])
{
    int choice;

    int x, neg;
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            myInformation();
            break;
        case 2:
            enterArray();
            break;
        case 3:
            disArray();
            break;
        case 4:
            printf("Enter number you want find:");
            scanf("%d", &x);
            int index = findX(x);
            if (index == -1)
            {
                printf("\nCan't find %d in array!\n", x);
            }
            else
            {
                printf("Value %d in positive %d", x, index);
            }
            break;
        case 5:
            neg = chknege(a[arr_size]);
            if (neg == 1)
            {
                printf("The array has negative number!");
            }
            else
            {
                printf("The array hasn't negativve number!");
            }
            break;
        }
    } while (choice >= 1 && choice <= 5);
    getch();
    return 0;
}
