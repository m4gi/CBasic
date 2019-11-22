#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define str_size 100

int main(int argc, char const *argv[])
{
    char str[str_size];
    int i, wrd;
    printf("\n\nCount the total number of words in a string:\n");
    printf("-------------------------------------------\n");
    printf("Input the string: ");
    gets(str);
    i = 0;
    wrd = 1;
    if (strlen(str) == 0)
    {
        wrd = 0;
    }
    else
    {
        while (str[i] != '\0')
        {
            if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            {
                wrd++;
            }
            i++;
        }
    }
    printf("Total number of words in the string is : %d\n", wrd);
    getch();
    return 0;
}
