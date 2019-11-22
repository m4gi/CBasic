#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    char ch;
    int vowels, con, other;
    vowels = 0;
    con = 0;
    other = 0;
    do
    {
        printf("Enter: ");
        fflush(stdin);
        scanf("%c", &ch);
        ch = toupper(ch);
        if (ch >='A' && ch <='Z')
        {
            switch (ch)
            {
            case 'A' :
            case 'E' :
            case 'I' :
            case 'O' :
            case 'U' :
                vowels++;
                break;
            }
        }
        else if (ch>= '1' && ch<='9')
            {
                con++;
            } else other++;
    } while (ch != '\n');
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", con);
    printf("Others: %d\n", other);
    getch();
    return 0;
}
