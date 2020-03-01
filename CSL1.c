#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
char *filename = "D:\\dictionary.txt";
void loadData(char **ArrWord, int sizeOfArr)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        fflush(stdin);
        printf("Can not open file!!!\n");
        return;
    }
    for (int i = 0; i < sizeOfArr; i++)
    {
        fgets(ArrWord[i], 30, f);
        ArrWord[i][strlen(ArrWord[i]) - 1] = '\0';
    }
    printf("The database has been loaded\n");
    printf("Well to the Spell Checker!!\n");
    fclose(f);
}

void standardString(char string[])
{
    int n = strlen(string);
    int i = 0, k = 0;
    char temp[30];
    while (string[i] == ' ')
    {
        string[i] = NULL;
        i++;
    }
    for (i = 0; i < n - 1; i++)
    {
        if (string[i] == ' ' && string[i + 1] == ' ')
        {
            string[i] = NULL;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (string[i] != NULL)
        {
            temp[k++] = string[i];
            temp[k] = '\0';
        }
    }
    strcpy(string, "");
    strcpy(string, temp);
    if (string[strlen(string) - 1] == ' ')
        string[strlen(string) - 1] = '\0';
    strlwr(string);
}

//kiem tra xem co phai la chuoi con hay k
int substring(char shortstr[], char longstr[])
{
    char *temp = NULL;
    temp = strstr(longstr, shortstr);
    if (temp != NULL)
    {
        free(temp);
        return 1;
    }
    return 0;
}

// kiem tra 2phan tu dau cua chuoi giong trong tu dien k
int subsequence(char shortstr[], char longstr[])
{
    char *d = shortstr;
    char *dEnd = shortstr + strlen(shortstr);
    for (; d < dEnd - 1; d++)
    {
        char p[5] = "";
        strncpy(p, d, 2);
        char *tem = NULL;
        tem = strstr(longstr, p);
        if (tem != NULL)
        {
            free(tem);
            return 1;
        }
    }
    return 0;
}

//kiem tra xem co phai la dao chu hay k
int permutation(char string1[], char string2[])
{
    int count = 0;
    int n1 = strlen(string1);
    int n2 = strlen(string2);
    char s1[30] = "";
    char s2[30] = "";
    strcpy(s1, string1);
    strcpy(s2, string2);
    if (n1 == n2)
    {
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                if (s1[i] == s2[j])
                {
                    count++;
                    s2[j] = NULL;
                    s1[i] = NULL;
                    break;
                }
            }
        }
    }
    if (count == n1)
    {
        return 1;
    }
    return 0;
}

//kiem tr xem co giong nhau hay k
int correctString(char **ArrWord, int sizeOfArr, char *String)
{
    for (int i = 0; i < sizeOfArr; i++)
    {
        if (strcmp(ArrWord[i], String) == 0)
            return 1;
    }
    return 0;
}

void checkString(char **ArrWord, int sizeOfArr, char *String)
{
    if (correctString(ArrWord, sizeOfArr, String))
    {
        printf("Great, %s is in the dictionary!\n", String);
        return;
    }
    printf("Here are the possible words you could have meant:\n");
    for (int i = 0; i < sizeOfArr; i++)
    {
        if ((subsequence(String, ArrWord[i]) || permutation(String, ArrWord[i]) || substring(String, ArrWord[i])) && (strlen(ArrWord[i]) <= strlen(String)))
        {
            printf("%s\n", ArrWord[i]);
        }
    }
}

void getString(char **ArrWord, int sizeOfArr)
{
    char String[30] = "";
    int num = 0;
    printf("Please enter the word you would like checked.\n");
    fflush(stdin);
    gets(String);
    standardString(String);
    checkString(ArrWord, sizeOfArr, String);
}

int getChoice(char choice[])
{
    char isTrue[10] = "yes";
    printf("\nWould you like to enter another word? (yes/no)\n");
    fflush(stdin);
    gets(choice);
    if (strcmp(choice, isTrue) == 0)
    {
        return 1;
    }
    return 0;
}

int main()
{
    char **ArrWord = NULL;
    int sizeOfArr = 349900;
    ArrWord = (char **)malloc(sizeOfArr * sizeof(char *));
    for (int i = 0; i < sizeOfArr; i++)
        ArrWord[i] = (char *)malloc(30 * sizeof(char));
    loadData(ArrWord, sizeOfArr);
    char choice[10] = "";
    do
    {
        fflush(stdin);
        getString(ArrWord, sizeOfArr);
    } while (getChoice(choice));
    return 0;
}
