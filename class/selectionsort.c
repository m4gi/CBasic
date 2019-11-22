#include <stdio.h>
void swap(int *v1, int *v2)
{
    int t = *v1;
    *v1 = *v2;
    *v2 = t;
}

int main(int argc, char const *argv[])
{
    int a[] = {5, 4, 1, 5, 7, 16, 3, 6};
    int n = sizeof(a) / sizeof(int);
    int i, j, minindex;
    for (i = 0; i <= n - 1; i++)
    {
        minindex = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[minindex] > a[j])
            {
                minindex = j;
            }
        }
        if (minindex > i) //swap
        {
            swap(&a[minindex], &a[i]);
        }
    }
    printf("Array after sort:\n");
    for (i = 0; i < 8; i++)
    {
        printf("%3d", a[i]);
    }

    getchar();
    getchar();
    return 0;
}
