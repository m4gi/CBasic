#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
const char *wd(int year, int month, int day)
{
    /* using C99 compound literals in a single line: notice the splicing */
    return ((const char *[]){"Monday", "Tuesday", "Wednesday",
                             "Thursday", "Friday", "Saturday", "Sunday"})[(
                                                                              day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) + (365 * (year + 4800 - ((14 - month) / 12))) + ((year + 4800 - ((14 - month) / 12)) / 4) - ((year + 4800 - ((14 - month) / 12)) / 100) + ((year + 4800 - ((14 - month) / 12)) / 400) - 32045) %
                                                                          7];
}
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    for (i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}
int main(int argc, char const *argv[])
{

    char s[30];
    int day[3];
    int x = 3;
    printf("Please enter a day(dd/mm/yyyy): ");
    fflush(stdin);
    scanf("%[^\n]", s);
    int n = strlen(s);
    for (int i = n - 1; i > 0; i--)
    {
        if (s[i] == '/')
        {
            s[i] = '\0';
            day[x -= 1] = atoi(&(s[i]) + 1);
        }
    }
    day[0] = atoi(s);
    printf("Day of year: %d\n", day_of_year(day[2], day[1], day[0]));
    printf("Day of week: %s\n", wd(day[2], day[1], day[0]));
    printf("Week of year: %d", day_of_year(day[2], day[1], day[0]) / 7 + 1);
    getch();
    return 0;
}
