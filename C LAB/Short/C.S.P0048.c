#include <stdio.h>
#include <string.h>
#include <conio.h>
void ReadFile(char filename[])
{
    FILE *f;
    char ch;
    fflush(stdin);
    f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Can't open file !!!\n");
        return;
    }
    ch = fgetc(f);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(f);
    }
    fclose(f);
}
int main(int argc, char const *argv[])
{
    FILE *f;
    char c[50];
    char ch;
    char filename[20];
    printf("=============== Text management ===============\n");
    printf("Enter file name to save the content: ");
    fflush(stdin);
    gets(filename);
    f = fopen(filename, "a+");
    printf("Enter content: ");
    fflush(stdin);
    gets(c);
    fprintf(f, "%s", c);
    fclose(f);
    printf("\n\nFile content: \n");
    ReadFile(filename);
    getch();
    return (0);
}