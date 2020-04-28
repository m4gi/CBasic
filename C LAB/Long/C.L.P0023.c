#include <stdio.h>
#include <string.h>
#include <conio.h>
void mystrcat();
void mystrchr();
void mystrcmp();
void mystrstr();
void mystrcpy();
void mystrncpy();
int main(int argc, char const *argv[])
{
    int opt;
    do
    {
        printf("\n Choose what you wanna try: \n");
        printf("\t1.strcat\n");
        printf("\t2.strcmp\n");
        printf("\t3.strcpy\n");
        printf("\t4.strncpy\n");
        printf("\t5.strstr\n");
        printf("\t6.strchr\n");
        printf("\t7.Exit!!\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);
        fflush(stdin);
        switch (opt)
        {
        case 1:
            mystrcat();
            break;
        case 2:
            mystrcmp();
            break;
        case 3:
            mystrcpy();
            break;
        case 4:
            mystrncpy();
            break;
        case 5:
            mystrstr();
            break;
        case 6:
            mystrchr();
            break;
        default:
            printf("Goodbye!!");
            return 0;
        }
    } while (opt > 0 && opt < 7);
    getch();
    return 0;
}
void mystrcat()
{
    int j = 0;
    char str1[100], str2[100];
    printf("Enter string 1: ");
    fflush(stdin);
    gets(str1);
    printf("Enter string 2: ");
    fflush(stdin);
    gets(str2);
    for (int i = strlen(str1); i < strlen(str1) + strlen(str2); i++)
    {
        str1[i] = str2[j];
        j++;
    }
    printf("Result: ");
    printf(str1);
}

void mystrcmp()
{
    char str1[100], str2[100];
    int r = 0;
    printf("Enter string 1: ");
    fflush(stdin);
    gets(str1);
    printf("Enter string 2: ");
    fflush(stdin);
    gets(str2);
    r = strcmp(str2, str1);
    printf("Result: %d", r);
}

void mystrcpy()
{
    char str1[100], str2[100];
    printf("Enter string 1: ");
    fflush(stdin);
    gets(str1);
    printf("Enter string 2: ");
    fflush(stdin);
    gets(str2);
    strcpy(str2, str1);
    printf("Result: ");
    puts(str2);
}

void mystrncpy()
{
    char str1[100], str2[100] = "";
    int n;
    printf("Enter string 1: ");
    fflush(stdin);
    gets(str1);
    printf("Enter string 2: ");
    fflush(stdin);
    gets(str2);
    do
    {
        printf("Enter numbers of character to copy: ");
        scanf("%d", &n);
    } while (n > strlen(str1));
    strncpy(str2, str1, n);
    printf("Result: %s\n", str2);
}
void mystrstr()
{
    char str1[100], str2[100], *result;
    printf("Enter string 1: ");
    fflush(stdin);
    gets(str1);
    printf("Enter substring to find: ");
    fflush(stdin);
    gets(str2);
    result = strstr(str1, str2);
    printf("The substring is: %s\n", result);
}

void mystrchr()
{
    char str[100], *result, c;
    printf("Enter string : ");
    fflush(stdin);
    gets(str);
    printf("Enter character: ");
    fflush(stdin);
    scanf("%c", &c);
    result = strchr(str, c);
    printf("The string start %c is : %s ", c, result);
}