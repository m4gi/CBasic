/*
Count the number of the appearance of letters in a string. 

Program Specifications 
Implement a program to prompt users to input a string.
Count the number of the appearances of letters in the string.
Function details: 
1. Function 1: Display a screen to prompt users to input a string.
o Users input a string, the perform Function 2. 
2. Function 2: The program counts the number of appearances of letters.
o Based on the ASCII table, create an array with 26 elements which are corresponding to 26 letters. 
o If the character is a letter (convert to lower case if it is upper case), increase by 1 at the letter’s position
(Assume the letter ‘a’ is the first position in the 26-letter array)  
o Return the 26-letter array after finishing counting the appearances of each letter in the inputted string. 
o Perform Function 3. 
3. Function 3: Output the letter and the number of its appearances.
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
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (arr[ch] != 0)
            {
                printf("%c: %d\n", ch, arr[ch]);
            }
        }
        printf("\nPress enter to continue, ESC to exit\n");
        fflush(stdin);
        c = getch();
    } while (c != 27);
    return 0;
}