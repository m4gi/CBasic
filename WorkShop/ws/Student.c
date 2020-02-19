#include <stdio.h>

int main(int argc, char const *argv[])
{
    int z=0,s = 5, i = 0;
    while (s>0)
    {
        /* code */
        z+= s*2;
        s-=3;
        
    }
    
    printf("%d", z--);
    getch();
    return 0;
}
