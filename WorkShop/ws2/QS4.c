#include <stdio.h>
int main(int argc, char const *argv[])

{
    int year;
    printf("Input a year :");
    scanf("%d", &year);
    if (year % 400 == 0)
        printf("%d is a leap year.\n", year);
    else if ((year % 100 != 0) && (year % 4 == 0))
        printf("%d is a leap year.\n", year);
    else
        printf("%d is not a leap year \n", year);
    getch();
    return 0;
}
