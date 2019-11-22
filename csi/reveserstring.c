#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    char s[50];
    int i,j,t,n,d;
    printf("Enter string: ");
    fflush(stdin);
    scanf("%[^\n]", &s);
    n = strlen(s);
    printf("Reverse string:");
    for(i=n-1;i>0;i--)
    {
        if(s[i]== ' ' )
        {
           s[i] = '\0';
            printf("%s ", &(s[i])+1);
        }
    }
    printf("%s", s);
    getch();
    return 0;
}
