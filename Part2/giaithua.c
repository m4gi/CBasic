#include <stdio.h>
int giaithua(unsigned int i)
{
    if (i <= 1)
    {
        return 1;
    }
    return i * giaithua(i - 1);
}
int main(int argc, char const *argv[])
{   
    int n = 10;
    scanf("%d", &n);
    printf("%d", giaithua(n));
    getch();
    return 0;
}
