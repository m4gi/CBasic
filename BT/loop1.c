#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int n;
    do 
        {
            printf("nhap vao: "); scanf("%d", &n);
            if (!(n>10 && n<100)) 
                {
                    printf("\n >> Ban nhap sai!\n");
                }    
                       
        }
    while (n<10 || n>100);
    getch();
    return 0;
}