#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a;
    printf("Enter number: ");
    scanf("%d", &a);
    if (a<0 || a>6)
        printf("Error");
    else 
        printf("The weekday is: ");
    {
        switch(a)
        {
            case 0: 
                printf("Monday");
                break;
            case 1:
                printf("Tuesday");
                break;
            case 2:
                printf("Wednesday");
                break;
            case 3:
                printf("Thursday");
                break;
            case 4:
                printf("Friday");
                break;
            case 5:
                printf("Saturday");
                break;
            case 6:
                printf("Sunday");
                break;
        } 
    }
    getch();
    return 0;
}
