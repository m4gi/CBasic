#include <stdio.h>
#include <conio.h>

int main(int argc, char  const *argv[])
{
    int n,i,j;
    printf("Enter nunber n: "); scanf("%d", &n);
    for (i=1; i<=n; i++)   // su dung vong lap de ve ra tam giac vuong
        {
            for (j=1; j<=i; j++)
                 printf("*");
            printf("\n");
        }
    getch();
    return 0;
}