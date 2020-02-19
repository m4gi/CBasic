#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
char *filename = "D:\\dictionary.txt";
char ch[10];
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
int main(int argc, char const *argv[])
{
    FILE *fptr;

    if ((fptr = fopen(filename, "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    return 0;
}
