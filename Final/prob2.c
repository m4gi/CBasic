#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, n;
    printf("nhap vao:");
    scanf("%d", &n);
    printf("tat ca cac uoc cua n la: ");
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
            printf("%d ", i);
    }
    getch();
    return 0;
}
