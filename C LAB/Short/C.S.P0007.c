/*
Create a program to remove all space not necessary between words in a string, keep only one space between 
two words.

Function details: 
1. Enter an string, do not allow enter special characters such as @, #, !, [, ], {, }, (, )
2. Remove all unnecessary blank in the string
3. Display the string on the screen
4. Continue to run program if press enter, Esc to exit
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

void RemoveLeft(char s[])
{
    int i = 0, j;
    while (s[i] == ' ')
    {
        if (s[i] == ' ')
        {
            for (j = i; j < strlen(s); j++)
            {
                s[j] = s[j + 1];
            }
        }
    }
}
void RemoveRight(char s[])
{
    int i = strlen(s) - 1, j;
    while (s[i] == ' ')
    {
        if (s[i] == ' ')
        {
            s[i] = s[i + 1];
            i--;
        }
    }
}
void RBetween(char s[])
{
    int i, j;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ' && s[i + 1] == ' ')
        {
            strcpy(&s[i], &s[i + 1]);
            i--;
        }
    }
}
int main(int argc, char const *argv[])
{
    char c, st[1000];
    int bool = 1;
    do
    {
        do
        {
            printf("Enter an string: ");
            fflush(stdin);
            gets(st);
            for (int i = 0; i < strlen(st); i++)
            {
                if ((st[i] == '@') || (st[i] == '#') || (st[i] == '!') || (st[i] == '[') || (st[i] == ']') || (st[i] == '{') || (st[i] == '}') || (st[i] == '(') || (st[i] == ')'))
                {
                    printf("The string has special characters!!! Please enter agian!\n");
                    bool = 0;
                }
            }
        } while (bool != 1);
        RemoveLeft(st);
        RemoveRight(st);
        RBetween(st);
        printf("The string after removing: ");
        puts(st);
        printf("\nPress enter to continue another reverse, ESC to exit\n");
        fflush(stdin);
        c = getch();
    } while (c != 27);
    return 0;
}
