#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int n,i,t;
    t=0;
    printf("Enter number: "); scanf("%d", &n);
    while (n != 0)
    {
        i = n % 10; //tach so 
        t+=i;   //cong so
        n/=10;  //giam so
    }
    printf("Sum of digits: %d", t);
    getch();
    return 0;
}