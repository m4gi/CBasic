#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[100];
    int i=0,mark;
    float total=0;
    printf("Program calculate the average of mathematics of some student!\n");
    do
    {
        printf("Enter mark:");
        scanf("%d", &mark);
        if(mark==0) break;
        total+=mark;
        i++;
    } while (mark>0);
    total = (float)total/(i);
    printf("Average mark of all student %.4f", total);
    getch();
    return 0;
}
