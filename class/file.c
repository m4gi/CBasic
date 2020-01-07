#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
int exist(char *filename)
{
    int existed = FALSE;
    FILE *f = fopen(filename, "r");
    if (f != '\0')
    {
        existed = TRUE;
        fclose(f);
    }
    return existed;
}
int writeFile(char *filename)
{
    if (exist(filename) == TRUE)
    {
        printf("File %s already existed. Rewrite? Y/N? :", filename);
        if (toupper(getchar()) == "N")
            return FALSE;
    }
    char line[201];
    int length = 0;
    FILE *f = fopen(filename, "w");
    fflush(stdin);
    do
    {
        gets(line);
        length = strlen(line);
        if (length > 0)
        {
            fputs(line, f);
            fputs("\n", f);
        }
    } while (length>0);
    fclose(f);
    return TRUE;
}
int printFile(char *filename)
{
    char c;
    if(exist(filename)== FALSE)
    {
        printf("The file %s does not exist.\n", filename);
        return FALSE;
    }
    FILE* f = fopen(filename, "r");
    while((c=fgetc(f))!=EOF) putchar(c);
    fclose(f);
    return TRUE;
}
int main(int argCount, char* args[])
{
    char filename[81];
    printf("Program for writing then redding a file \n");
    printf("Enter the file name: ");
    gets(filename);
    printf("write file:\n");
    if (writeFile(filename)==TRUE)
    {
        printf("Data in the file %s: \n", filename);
        if(printFile(filename)==FALSE) printf("File error!!\n");
    }
    else printf("Writing file fail!\n", filename);
    getchar();
    getchar();
    return 0;
}
