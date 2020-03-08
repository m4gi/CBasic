#include <stdio.h>
#include <string.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    FILE *f;
    char filename[15];
    char ch;
    fflush(stdin);
    printf("File name: ");
    scanf("%s", filename);
    f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Can't open file !!!\n");
        return;
    }
    printf("File content:\n");
    ch = fgetc(f);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(f);
    }
    fclose(f);
    getch();
    return 0;
}