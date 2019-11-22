#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[100];
    int i, n, odd=0, even=0;
    printf("Input n:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("A[%d] = ", i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        if(a[i] % 2) 
        {
            odd+=a[i];
        }
        else
        {
            even+=a[i];
        }
    }
    printf("Sum of even: %d\nSum of odd: %d", even, odd);
    getch(); 
    return 0;
}
