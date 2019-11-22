#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int i;
    for(i=0;i<255;i++)
    {
        printf("%d : %c %o %x\n", i, i, i, i);
    }
    getch();
    return 0;
}
