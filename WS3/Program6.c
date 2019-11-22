#include <stdio.h>
#include <conio.h>

int isfibo(int n)
{
    int t1=1, t2=1, f=1;
    if(n==1) return 1;
    while (f<n)
    {
        f=t1+t2;
        t1=t2;
        t2=f;
    }
    return n==f;
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Input number: ");
    scanf("%d", &n);
    if(isfibo(n))
    {
        printf("Number %d is fibonaci", n);
    } else  printf("Number %d is not fibonaci", n);
    getch();
    return 0;
}

