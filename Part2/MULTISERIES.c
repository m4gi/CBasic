#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int i,n,t;
    t=1;
    printf("Enter number: "); scanf("%d", &n);
    printf("Result: ");
    for (i=1;i<=n;i++)  
    {
        printf("%d",i);
        if (i<n) printf("x");
            else printf(" = ");
        t*=i;  // tính giai thừa của n
    }
    printf("%d.", t);
    getch();
    return 0;   
}