#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int i,j,n;
    i=0; j=0;
    while ((n<10 || n>100 ))
    {
        printf("nhap vao: "); scanf("%d", &n);
        if (n<10 || n>100) 
            {
                printf("so nhap khong hop le.");
                ++i;
                ++j;
                printf("\nso lan nhap sai: %d .\n",j);
            }
         if (i>=5) break;
    }
    getch();
    return 0;
}
