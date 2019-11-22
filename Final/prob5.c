#include <stdio.h>
#include <string.h>
#define max 100

int main(int argc, char const *argv[])
{
    char s[max];
    printf("Nhap chuoi: ");
    gets(s);
    int a[max], m = 0;
    int n = strlen(s) - 1;
    int i, j;
    for (i = 0; i <= n; i++)
    {
        int d = 0;
        for (j = 0; j <= n; j++)
        {
            j = 0;
            while (j <= n)
            {
                if (s[i] == s[j])
                {
                    d++;
                }
                j++;
            }
        }
        a[m] = d;
        m++;
    }
    int k;
    int maxx = a[0];
    int maxi = 0;
    for (k = 0; k < m; k++)
    {
        if (a[k] > maxx)
        {
            maxx = a[k];
            maxi = k + 1;
        }
    }
    printf("chu xuat hien nhieu nhat %d lan.", maxx);
    getch();
    return 0;
}