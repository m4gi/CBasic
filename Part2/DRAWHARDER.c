#include <stdio.h>
#include <conio.h>

int main(int argc, char  const *argv[])
{
    int n,i,j;
    printf("Enter nunber n: "); scanf("%d", &n);
    for (i=n; i>=1; i--)  
        {
            for (j=i; j>=1; j--)
                 printf("*");
            printf("\n");
        }
    printf("\n\n");    
    for(i = n; i >= 1; i--) 
        {
            for(j=1; j <= i; j++)
                printf(" "); 
            for(j=i; j <= n; j++)
                 printf("*");
            printf("\n");
        }
    printf("\n\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
            printf(" ");
        for(j=1;j<=i;j++)
            printf("* ");
        printf("\n");
    }
    printf("\n\n");
    for(i=n;i>=1;i--)
    {
        for(j=1;j<=n-i;j++)
            printf(" ");
        for(j=1;j<=i;j++)
            printf("* ");
        printf("\n");
    }
    getch();
    return 0;
}