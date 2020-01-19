/*
Print multiplication table for an input number 
Program Specifications 
Create a program to print to the screen multiplication table for an input number from 1 to 9. Function details:  
1. Enter a number from 1 to 9, do not allow user enter other characters
2. Print multiplication table corresponding with the number input.
3. Program continues to run if press enter, exit if press Esc.
*/
#include <stdio.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    int n,i;
    char c;
    do
    {
        do
        {
            printf("Please enter a number (1-9):");
            scanf("%d", &n);
        } while (n<1 || n>9);
        printf("Multiplication table for %d number:\n", n);
        for (i = 1; i <= 9; i++)
        {
            printf("%d x %d = %d\n", n, i, n * i);
        }
        printf("-------------------------------------------\nPress enter to continue, Esc to exit.\n");
        c = getch();
    } while (c != 27);
    return 0;
}