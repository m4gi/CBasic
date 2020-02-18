/*
Program to look up character that appears the most in a string. 

Function details:  
1. Enter a string
2. Display each character and times of appearance in the string
3. Display character that appears the most in the string.
4. Program continues to run if press enter, exit if press Esc.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int arr[256];
    char c, s[1000];
    memset(arr, 0, sizeof(arr));
    do
    {
        printf("Enter string:");
        gets(s);
        for (int i = 0; i < strlen(s); i++)
        {
            arr[s[i]] += 1;
        }
        for (int ch = 65; ch <= 122; ch++)
        {
            if (arr[ch] != 0)
            {
                printf("%c: %d\n", ch, arr[ch]);
            }
        }

        printf("\nPress enter to continue another , ESC to exit\n");
        fflush(stdin);
        c = getch();
    } while (c != 27);
    return 0;
}
