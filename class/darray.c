#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
int isFull(int *a, int n)
{
    return n == MAXN;
}
int isEmpty(int *a, int n)
{
    return n == 0;
}
int add(int x, int *a, int *pn)
{
    a[*pn] = x;
    (*pn)++;
}
void check(int *a, int n)
{
    if (isEmpty(*a, n) == 0)
        printf("\nArray is empty!!!");
    else if (isFull(*a, n) == MAXN)
    {
        printf("\nArray is full!!!");
    }
}
int uChoice()
{
    int choice;
    printf("\n 1. Test array full or not.");
    printf("\n 2. Test array empty or not.");
    printf("\n 3. Adding an element increase number of elements.");
    printf("\n 4. Quit!!!\n");
    printf("\nInput [1..4]: ");
    scanf("%d", &choice);
    return choice;
}
int main(int argc, char const *argv[])
{
    int a[100];
    int n = 0;
    int value;
    int choice;
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            if (isFull(a, n))
            {
                printf("\nSorry, the array is Full!!!");
            }
            else
            {
                printf("Input an added value:");
                scanf("%d", &value);
                add(value, a, &n);
                printf("Added\n");
            }
            break;
        case 2:
            if (isEmpty(a, n))
                printf("\nSorry! The array is empty!!!\n");
            else
            {
                printf("Input the searched value:");
                scanf("%d", &value);
                int pos = search(value, a,n);
                if(pos<0) printf("Not Found\n");
                else printf("Postion is found: %d", pos);
            }

            break;
        case 3:
            printf("Add");
            break;
        default:
            printf("Input number 1->4.");
        }
    } while (choice >= 1 && choice <= 3);
    getch();
    return 0;
}
