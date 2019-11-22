#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    if(n>0)
    {
        printf("Number is positive");
    } else printf("Number is negetive");
    getch();
    return 0;
}
