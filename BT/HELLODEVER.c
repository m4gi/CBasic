#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    char st[50];
    printf("Enter your name: ");
    gets(st);
    printf("%s is a member of FU-Dever!",st);
    getch();
    return 0;
}