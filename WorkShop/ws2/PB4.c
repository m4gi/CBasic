#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x, y, t;
    do
    {
        printf("Enter x:");
        scanf("%d", &x);
        printf("Enter y:");
        scanf("%d", &y);
        t = x;
        x = y;
        y = t;
        printf("Swap x,y:\nx=%d\ny=%d\n\n", x, y);
    } while (x != 0 && y != 0);
    return 0;
}

