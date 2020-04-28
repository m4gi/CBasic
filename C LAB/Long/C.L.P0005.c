#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
char *filename;
int n;
typedef struct DATA
{
    char OCity[20];
    char DCity[20];
    int Seat;
} DATA;
DATA List[MAX][1];
typedef struct test
{
    DATA temp[10];
} test;
test book[31];
void LoadData(char filename[])
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        fflush(stdin);
        printf("Can not open file!!!\n");
        return;
    }
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%s %s %d", List[i][0].OCity, List[i][0].DCity, &List[i][0].Seat);
    }
    for (int j = 0; j < 31; j++)
    {
        for (int i = 0; i < n; i++)
        {

            book[j].temp[i] = List[i][0];
        }
    }
    fclose(f);
}
void Reservation()
{
    char name[30], OCity[20], DCity[20];
    int LDay, BDay, seat, check = 0;
    printf("What is your name, first followed by last?\n");
    fflush(stdin);
    gets(name);
    printf("From which city do you want to fly?\n");
    fflush(stdin);
    gets(OCity);
    printf("What is your destination city?\n");
    fflush(stdin);
    gets(DCity);
    printf("Which day do you want to leave?\n");
    scanf("%d", &LDay);
    printf("Which day do you want to come back?\n");
    scanf("%d", &BDay);
    printf("How many seat do you want?\n");
    scanf("%d", &seat);
    if ((LDay > BDay) || (LDay > 10) || (BDay > 10))
    {
        printf("Sorry, that reservation could not be made.\n");
        printf("The days of flight are invalid.\n");
        return;
    }
    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (strcmp(book[i].temp[j].OCity, OCity) == 0 && strcmp(book[i].temp[j].DCity, DCity) == 0 && i == LDay)
            {
                if (book[i].temp[j].Seat > 0 && (book[i].temp[j].Seat - seat >= 0))
                {
                    book[i].temp[j].Seat -= seat;
                    check = 1;
                    break;
                }
            }
        }
        if (check == 1)
            break;
    }
    if (check == 0)
    {
        printf("We don't have flights to and from %s and %s\n", OCity, DCity);
        return;
    }

    check = 0;
    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (strcmp(book[i].temp[j].OCity, DCity) == 0 && strcmp(book[i].temp[j].DCity, OCity) == 0 && i == BDay)
            {
                if (book[i].temp[j].Seat > 0 && (book[i].temp[j].Seat - seat >= 0))
                {
                    book[i].temp[j].Seat -= seat;
                    check = 1;
                    break;
                }
            }
        }
        if (check == 1)
            break;
    }
    if (check == 0)
    {
        printf("We don't have flights to and from %s and %s\n", DCity, OCity);
        return;
    }
    printf("Thanks, you reservation has been made\n");
}
void ListFlight()
{
    printf("\nHere is the information for each flight on each day:\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("\nDay %d\n", i);
        for (int j = 0; j < n; j++)
        {
            printf("\nTo: %s From: %s Available Seats:  %d", book[i].temp[j].OCity, book[i].temp[j].DCity, book[i].temp[j].Seat);
        }
        printf("\n");
    }
}
int uChoice()
{
    int choice;
    printf("\nWhich of the following choices do you want?\n");
    printf("\n 1- Make a reservation.");
    printf("\n 2- Print out a listing of all flights.");
    printf("\n 3- Quit.");
    printf("\nEnter your choice:  ");
    scanf("%d", &choice);
    return choice;
}
int main(int argc, char const *argv[])
{
    int choice;
    char filename[30];
    printf("Enter the name of the file with the flight data.\n");
    fflush(stdin);
    gets(filename);
    LoadData(filename);
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            Reservation();
            break;
        case 2:
            ListFlight();
            break;
        }
    } while (choice >= 1 && choice <= 2);
    return 0;
}
