#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x,sum=0;
    do
    {
        printf("Enter num:");
        scanf("%d", &x);
        sum+=x;
    } while (x!=0);
    printf(">>Result: %d", sum);
    return 0;
}

