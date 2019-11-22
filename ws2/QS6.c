#include <stdio.h>
#include <conio.h>

int main()
{
    char ch;
    printf("Input a character: ");
    scanf("%c", &ch);
    fflush(stdin);
    ch = toupper(ch);
    if(ch >= 'A' && ch <= 'Z')x
    {
        printf("This is an alphabet.\n");
    }
    else if (ch >= '0' && ch <= '9')
    {
        printf("This is a digit.\n");
    }
    else
    {
        printf("This is a special character.\n");
    }
    return 0;
}
