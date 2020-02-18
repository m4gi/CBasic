#include <stdio.h>
#include <conio.h>
int n;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}
void input(int a[])
{
    printf("Please enter size of array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
void add(int a[])
{
    printf("\nPlease enter new value: ");
    scanf("%d", &a[n++]);
}

void output(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int main(int argc, char const *argv[])
{
    int a[100];
    char c;
    do
    {
        input(a);
        quickSort(a, 0, n);
        printf("The array after sorting:\n");
        output(n, a);
        add(a);
        quickSort(a, 0, n);
        printf("New array:\n");
        output(n, a);
        printf("\nPress enter to continue another reverse, ESC to exit\n");
        fflush(stdin);
        c = getch();
    } while (c != 27);
    return 0;
}
