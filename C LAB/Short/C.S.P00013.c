#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define MAXA 100
int EnterA(float array[])
{
    int i = 0;
    float n;
    printf("Please enter the number:\n");
    while (i <= MAXA)
    {
        scanf("%f", &array[i]);
        if (array[i] == -999)
            break;
        if (array[i] < 0 || array[i] > 100)
            printf("Number must be from 0 to 100!\n");
        else if (i == MAXA)
            printf("The Array Is Full!!!\n");
        else
            i++;
    }
    return i;
}
int FindMax(float array[], int n)
{
    int i = 1, x;
    float max = array[0];
    for (; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            x = i;
        }
    }
    return x;
}
int FindMin(float array[], int n)
{
    int i = 1, x;
    float min = array[0];
    for (; i < n; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
            x = i;
        }
    }
    return x;
}
float FindMean(float array[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }
    return sum / n;
}
float FindSD(float array[], int n)
{
    float result = 0;
    float mean = FindMean(array, n);
    for (int i = 0; i < n; i++)
    {
        result += pow((mean - array[i]), 2);
    }
    return sqrt(result / n);
}
void DispayMSD(float array[], int n)
{

    printf("The adjusted mean is %.2f\n", FindMean(array, n));
    printf("The adjusted standard deviation is %.2f\n", FindSD(array, n));
}
int MaxMin(float array[], int n)
{
    int min = FindMin(array, n);
    int max = FindMax(array, n);
    printf("\nThe data has been adjusted by removing the minimum %.2f.\n", array[min]);
    printf("The data has been adjusted by removing the maximum %.2f.\n", array[max]);
    for (int j = min; j < n; j++)
    {
        array[j] = array[j + 1];
    }
    n--;
    for (int j = max; j < n; j++)
    {
        array[j] = array[j + 1];
    }
    return --n;
}
void swap(float *a, float *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(float array[], int low, int high)
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
void quickSort(float array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}
void Histogram(float array[], int n)
{
    quickSort(array, 0, n);
    int temp[21];
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i <= n; i++)
    {
        int a = array[i] / 5;
        temp[a]++;
    }
    printf("\nHere is a histogram of the adjusted data:\n\n");
    for (int i = 0; i <= 20; i++)
    {
        if (i == 20)
        {
            printf("%6d|", 100);
            if (temp[i] > 0)
                for (int j = 0; j < temp[i]; j++)
                    printf("*");
        }
        else
        {
            if (i < 2)
                printf("%3d- %d|", i * 5, i * 5 + 4);
            else
                printf("%d- %d|", i * 5, i * 5 + 4);
            if (temp[i] > 0)
                for (int j = 0; j < temp[i]; j++)
                    printf("*");
        }
        printf("\n");
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    float arr[MAXA];
    int n, m;
    char c;
    do
    {
        memset(arr, 0, sizeof(arr));
        n = EnterA(arr);
        m = MaxMin(arr, n);
        DispayMSD(arr, m);
        Histogram(arr, m);
        printf("\nPress enter to continue another reverse, ESC to exit\n");
        fflush(stdin);
        c = getch();
    } while (c != 27);
    return 0;
}
