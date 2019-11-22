#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    long a[10], n,t,q;
    int i,j =0;
    char hex[100];
    memset(hex, '\0', 100);
    printf("Enter number: ");
    scanf("%d", &n);
    q = n;
    for (i = 0; n > 0; i++)
    {
        a[i] = n % 2;
        n = n / 2;
    }
    while(q!= 0)
    {
        t = q % 16;
        if (t < 10)
            hex[j++]= 48 + t;   
        else 
            hex[j++]= 55 + t;
        q = q / 16;   
    }
    printf("\nConvert decimal to binary = ");
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", a[i]);
    }
    printf("\nConvert decimal to hexadecmal =");
    for (i=j;i>=0;i--)
    {
        printf("%c", hex[i]);
    }
    getch();
}