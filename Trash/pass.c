#include <stdio.h>
#include <conio.h>
#include <string.h>
void hash();
int main(int argc, char const *argv[])
{
    char ch1[30], ch2[30];
    printf("Enter password: ");
    gets(ch1);
    printf("Enter password: ");
    gets(ch2);
    hash(ch1,ch2);
    // if(strstr(ch1,ch2))
    // {
    //     printf("Correct password");
    // }   else printf("Incorrect password");
    getch();
    return 0;
}
void hash(char s1[30], char s2[30])
{
    int i;
    char s[60];
    for (i = 0; i < strlen(s1); i++)
    {
        if(s1[i]==s2[i])
        {
            printf("Correct password");
        }
        else
            printf("Incorrect password");
    }
   
}