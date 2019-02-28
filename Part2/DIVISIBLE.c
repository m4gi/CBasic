#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int n,i,d;
    printf("Input:\n");
    printf("n: "); scanf("%d", &n);
    printf("d: "); scanf("%d", &d);
    printf("Output:\n");
    for (i=1;i<=n;i++) // kiem tra cac so tu 1 den n 
    {
        if (!(i % d))   // neu chia het thi in ra
            printf("%d ", i);
    }
    getch();
    return 0;
}