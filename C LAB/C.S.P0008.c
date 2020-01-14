/*
Create a program to look up all characters appear one time in a string. 

Function details: 
1. Enter an string
2. Loop up characters appear one time in the string (do not distinguish lower and upper case)
3. Display all found characters on the screen
4. Continue to run program if press enter, Esc to exit
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    char c, st[1000];
    int i;
    int arr[256];
    memset(arr, 0, sizeof(arr));
    do
    {
        printf("Enter an string: ");
        gets(st);
        for (i = 0; i < strlen(st); i++)
        {
            if (st[i] >= 65 && st[i] <= 90)
                st[i] += 32;
        }
        for (i = 0; i < strlen(st); i++)
        {
            arr[st[i]] += 1;
        }
        printf("Found characters: ");
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (arr[ch] == 1)
            {
                printf("%c\t", ch);
            }
        }
        printf("\nPress enter to continue another reverse, ESC to exit\n");
        fflush(stdin);
        c = getch();
    } while (c != 27);
    return 0;
}