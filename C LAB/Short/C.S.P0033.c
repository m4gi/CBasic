#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int SumOfArray(int n, int *arr)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    char c;

    do
    {
        int *arr;
        int n;
        printf("Dynamic memory allocation: \n");
        printf("\tNumber of element n: ");
        do
        {
            scanf("%d", &n);
            if (n <= 0)
                printf("Please enter n > 0 !!\n");
        } while (n <= 0);
        arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            printf("\tEnter an integer: ");
            scanf("%d", &arr[i]);
        }
        int sum = SumOfArray(n, arr);
        free(arr);
        printf("\tSum = %d\n", sum);
        printf("-------------------------------------------\nPress enter to continue, Esc to exit.\n");
        c = getch();
    } while (c != 27);
    return 0;
}
