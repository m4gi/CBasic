#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int n,m,i,t=1;
    printf("Enter a number: "); scanf("%d", &n);
    printf("Enter a number: "); scanf("%d", &m);
    for(i=1;i<=m;i++)       //tinh so mu bang m lan cua n
        t*=n;       
    printf(">> Output: %d^%d = %d", n,m,t);
    getch();
    return 0;
}
