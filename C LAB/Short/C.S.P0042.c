#include <conio.h>
#include <stdio.h>
void Input(int a[])
{
    int i = 0;
    printf("Enter the elements of array: \n");
    do
    {
        scanf("%d", &a[i++]);
    } while (a[i - 1] != 0);
}
void Display(int a[])
{
    int i = 0;
    printf("\nArray elements: \n");
    while (a[i] != 0)
    {
        printf("%d ", a[i]);
        i++;
    }
}
void Find(int a[])
{
    int i = 1;
    int max = a[0];
    while (a[i] != 0)
    {
        if (a[i] > max)
            max = a[i];
        i++;
    }
    printf("\nArray maximum value: \nThe max is %d", max);
}
void Even(int a[])
{
    int i = 0;
    printf("\nArray even value: \n");
    while (a[i] != 0)
    {
        if (a[i] % 2 == 0)
            printf("%d ", a[i]);
        i++;
    }
}
int main()
{
    int arr[100];
    Input(arr);
    Display(arr);
    Find(arr);
    Even(arr);
    getch();
    return 0;
}