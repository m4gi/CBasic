#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int a,i,n,t,s=0;
    t=1;
    printf("Enter number: "); scanf("%d", &n);
    printf("Sum of series ");
    for (i=1; i<=n; ++i)
    {
        a=t*3;
        s+=a;
        t=((t*10)+1);
        printf("%d", a);
        if (i<n) printf(" + "); else printf (" = ");
         
    }
    printf("%d", s);
    getch();
    return 0;
}