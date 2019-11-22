#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

long n;
int i, j = 0;

int main(int argc, char const *argv[])
{
    char c='y';
    while (c =='y' || c == 'Y')
    {
        printf("Enter number: ");
        scanf("%ld", &n);
        hexa(n);
        bin(n);
        oct(n);
        getch();
        printf("\n\nPress any key to exit!!.\nDO YOU WANT TO CONTINUE? YES(Y):");
        fflush(stdin);
        scanf("%c", &c);
    }
    return 0;
}
int hexa(int q)
{
    long t;
    char hex[100];
    memset(hex, '\0', 100);
    while (q != 0)
    {
        t = q % 16;
        if (t < 10)
            hex[j++] = 48 + t;
        else
            hex[j++] = 55 + t;
        q = q / 16;
    }
    printf("\nConvert decimal to hexadecmal =");
    for (i = j; i >= 0; i--)
    {
        printf("%c", hex[i]);
    }
    return 0;
}
int bin(int q)
{
    long a[10];

    for (i = 0; q > 0; i++)
    {
        a[i] = q % 2;
        q = q / 2;
    }
    printf("\nConvert decimal to binary = ");
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", a[i]);
    }
    return 0;
}

int oct(int q)
{
    int o[50], i = 0;
    while (q != 0)
    {
        o[i] = q % 8;
        q = q / 8;
        i++;
    }
    printf("\nConvert decimal to octal = ");
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", o[i]);
    }
    return 0;
}