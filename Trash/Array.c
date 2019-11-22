#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[10];
    int i;
    for(i=0;i<10;i++)
    {
        printf("Enter %d elements: ", i);
        scanf("%d", &arr[i]);
    }
    for(i=0;i<10;i++)
    {
        printf("%10d", arr[i]);
    }
    getch();
    return 0;
}
