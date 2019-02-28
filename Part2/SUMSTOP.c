#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int n,sum;
    sum=0;
    while (n!=0)    // tinh tong khi nhap n=0 thi in ra ket qua
    {
        printf("Enter number: "); scanf("%d", &n);
        sum+=n;
    }
    printf("Sum: %d", sum);
    getch();
    return 0;
}