/*
Reverse a string; convert to upper case and vice versa. 
Program Specifications 
Implement a program that asks users a string.
Then, reverse the string; and convert lowercase to uppercase and vice versa.
Function details: 
1. Function 1: Display a screen to prompt users to input a string.
o Users run the program and ask users to input a string.  
o Users input a string; perform Function 2. 
2. Function 2: Reverse the string and convert uppercase to lowercase and vice versa.
o The program reverses the string. During the reversing process, perform Function 3 to convert uppercase to 
lowercase and vice versa. 
o After reversing the string, returns the new reversed string. 
o Perform Function 4. 
3. Function 3: Convert uppercase to lowercase and vice versa. 
o The program takes input as a string. 
o If a letter is uppercase, convert to lowercase. 
o If a letter is lowercase, convert to uppercase. 
4. Function 4: Output the new string to the screen.     */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void input(char str[])
{
    printf("Enter string: ");
    fflush(stdin);
    gets(str);
}

void reverse(char s[])
{
    for (int i = 0; i < strlen(s) / 2; i++)
    {
        char temp = s[i];
        s[i] = s[strlen(s) - 1 - i];
        s[strlen(s) - 1 - i] = temp;
    }
}
void process(char s[])
{
    for (int i = 0; i < strlen(s) - 1; i++)
    {
        if (isalpha(s[i]) != 0)
        {
            if (isupper(s[i]) != 0)
            {
                s[i] += 32;
            }
            else if (islower(s[i]) != 0)
            {
                s[i] -= 32;
            }
        }
    }
}
void output(char s[])
{
    printf("%s", s);
}
int main(int argc, char const *argv[])
{
    char s[1000], c;
    do
    {
        input(s);
        printf("The old string:");
        output(s);
        process(s);
        reverse(s);
        printf("\nNew string: \n");
        output(s);
        printf("\nPress enter to continue another , ESC to exit\n");
        fflush(stdin);
        c = getch();
    } while (c != 27);
    return 0;
}
