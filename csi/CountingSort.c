#include <stdio.h>

void counting_sort(int a[], int n, int max)
{
    int count[50] = {0}, i, j;

    for (i = 0; i < n; ++i)
        count[a[i]]++;

    printf("\nSorted elements are:");

    for (i = 0; i <= max; ++i)
        for (j = 1; j <= count[i]; ++j)
            printf("%d ", i);
}
int main()
{
    int a[50], n, i, max = 0;
    printf("Enter number of elements:");
    scanf("%d", &n);
    printf("\nEnter elements:\n");

    for (i = 0; i < n; ++i)
    {
        printf("A[%d] = ", i);
        scanf("%d", &a[i]);
        if (a[i] > max)
            max = a[i];
    }
    counting_sort(a, n, max);
    getchar();
    getchar();
    return 0;
}