#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a,b,t;
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);
    t = a + b;
    printf("Tong la: %d", t);
    getch();
    return 0;
}
