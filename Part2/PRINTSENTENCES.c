#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int i,n;
    printf("Enter number: "); scanf("%d", &n);
    printf("Output:\n");
    while (i!=n)
        {
            printf("This is the sentence: "); 
            scanf("%d", &i);    
        }
    getch();
    return 0;
}