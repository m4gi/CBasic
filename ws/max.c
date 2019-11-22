#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int x,y,z,result,max;
    printf("Input the first integer:");
    scanf("%d", &x);
    printf("Input the second integer:");
    scanf("%d", &y);
    printf("Input the third integer:");
    scanf("%d", &z);
    result=(x+y+abs(x-y))/2;
    max=(result+z+abs(result-z))/2;
    printf("Maximum of three: %d", max);
    getch();
    return 0;
}
