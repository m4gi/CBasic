#include <stdio.h>

void input(int a[], int *pn)
{
    int i=0;
    do
    {
        printf("\nEnter a[%d]=", i);
        scanf("%d", &a[i]);
        i++;
    } while (a[i-1]!=0)    
}
void display(int a[], int n)
{
    int i;
    printf("\nDisplay array\n");
    for (i = 0; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
}
int findmax(int a[], int n)
{
    int i, max;
    max = a[0];
    printf("\n---------Find Max--------\n");
    for (i = 1; i <= n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    printf("\nMax of array : %d\n", max);
    return max;
}
int displayeven(int a[], int n)
{
    printf("\n---------Display Even--------\n");
    int i;
    printf("\nEven of array: ");
    for (i = 0; i <= n; i++)
    {
        if ((a[i] % 2) == 0)
            printf("%d ", a[i]);
    }
}
int main(int argc, char const *argv[])
{
    int size = 5;
    int a[100];
    input(a);
    display(a, size);
    findmax(a, size);
    displayeven(a, size);
    getch();
    return 0;
}
