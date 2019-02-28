#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int n,i,t;
    t=0;
    printf("Enter number: "); scanf("%d", &n);
    printf(">>Number after reserve:  ");
    while (n != 0)   // dao so 
    {
        i = n % 10;
        printf("%d", i);
        n/=10;
    } 
    getch();
    return 0;
}