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
void outputArray(int array[], int size)
{
    printf("Array: ");
    for (int i = 0; i <= size; i++)
        printf("%d ", array[i]);
}
void outputArray1(int array[], int size)
{
    printf("Array: ");
    for (int i = size; i >= 0; i--)
        printf("%d ", array[i]);
}
void AddArray(int a[], int *size)
{
    printf("Please input an integer: ");
    scanf("%d", &a[(*size)]);
    printf("\nAdd value successful!");
    (*size)++;
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
void DeleteFirst(int array[], int *size)
{
    int n, temp = 0;
    printf("Please input an integer to remove: ");
    scanf("%d", &n);
    for (int i = 0; i < *size; i++)
        if (array[i] == n)
        {
            for (int j = i; j < (*size) - 1; j++)
                array[j] = array[j + 1];
            (*size)--;
            temp++;
            break;
        }
    if (temp == 0)
        printf("%d is not in the array\n", n);
    printf("The array after removing: \n");
    outputArray(array, *size);
}
void DeleteAll(int array[], int *size)
{
    int n, temp = 0;
    printf("Please input an integer to remove: ");
    scanf("%d", &n);
    for (int i = 0; i < *size; i++)
        if (array[i] == n)
        {
            for (int j = i; j < (*size) - 1; j++)
                array[j] = array[j + 1];
            (*size)--;
            temp++;
        }
    if (temp == 0)
        printf("%d is not in the array\n", n);
    printf("The array after removing: \n");
    outputArray(array, *size);
}
int uChoice()
{
    int choice;
    printf("\n=================MENU================\n");
    printf("\n 1- Add a value.");
    printf("\n 2- Search a value.");
    printf("\n 3- Remove the first existence of a value.");
    printf("\n 4- Remove all existences of a value.");
    printf("\n 5- Print out the array.");
    printf("\n 6- Sort the array in ascending order (positions of elements are preserved).");
    printf("\n 7- Sort the array in descending order (positions of elements are preserved).");
    printf("\n Others- Quit");
    printf("\nInput [1..7]:  ");
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
            DeleteFirst(array, &size);
            break;
        case 4:
            DeleteAll(array, &size);
            break;
        case 5:
            outputArray(array, size);
            break;
        case 6:
            quickSort(array, 0, size);
            outputArray(array, size);
            break;
        case 7:
            quickSort(array, 0, size);
            outputArray1(array, size);
            break;
        default:
            exit(1);
        }
    } while (choice >= 1 && choice <= 7);
    getch();
    return 0;
}