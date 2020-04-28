#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

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
void AddArray(int a[], int *size)
{
    printf("Please input an integer: ");
    scanf("%d", &a[(*size)]);
    printf("\nAdd value successful!");
    (*size)++;
}
void OutputArray(int array[], int size)
{
    if (size == 0)
    {
        printf("\nEmpty Array!");
        return;
    }
    for (int i = 0; i < size; i++)
        printf("\nArray[%d] = %d", i, array[i]);
}
void Search(int array[], int size)
{
    int n, count = 0;
    int positions[size];
    printf("Please input an integer to search: ");
    scanf("%d", &n);
    for (int i = 0; i < size; i++)
        if (array[i] == n)
            positions[count++] = i;
    if (count == 0)
        printf("%d is not in the array\n", n);
    else
    {
        printf("Its positions: ");
        for (int i = 0; i < count; i++)
            printf("%d ", positions[i]);
    }
}
void PrintMinMax(int array[], int size)
{
    int min, max;
    if (size == 0)
    {
        printf("\nEmpty Array!");
        return;
    }
    printf("Enter min value: ");
    scanf("%d", &min);
    printf("Enter max value: ");
    scanf("%d", &max);
    for (int i = min; i <= max; i++)
    {
        printf("\nArray[%d] = %d", i, array[i]);
    }
}
int uChoice()
{
    int choice;
    printf("\n=================MENU================\n");
    printf("\n 1- Add a value.");
    printf("\n 2- Search a value.");
    printf("\n 3- Print out the array.");
    printf("\n 4- Print out values in a range of inputted min and max values, inclusively.");
    printf("\n 5- Sort the array in ascending order.");
    printf("\n Others- Quit");
    printf("\nInput [1..5]:  ");
    scanf("%d", &choice);
    return choice;
}
int main(int argc, char const *argv[])
{
    int array[MAX];
    int choice, size = 0;
    memset(array, 0, sizeof(array));
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            AddArray(array, &size);
            break;
        case 2:
            Search(array, size);
            break;
        case 3:
            OutputArray(array, size);
            break;
        case 4:
            PrintMinMax(array, size);
            break;
        case 5:
            quickSort(array, 0, size);
            printf("\nArrays have been sorted!!!");
            break;
        default:
            exit(1);
        }
    } while (choice >= 1 && choice <= 5);
    getch();
    return 0;
}