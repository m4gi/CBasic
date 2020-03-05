/*
Management Hotel Room management.
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
char *filename = "hotellog.txt";
char *fileout = "summary.txt";
void OpenFile()
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        fflush(stdin);
        printf("Can not open file!!!\n");
        getch();
        exit(1);
    }
    fclose(f);
}
void Checkin(FILE *fi, FILE *fo, int n, char lastName[][30], int status[n], int occupants[n])
{
    int available = FALSE;
    int i;
    for (i = 0; i < n; i++)
        if (status[i] == FALSE)
        {
            fscanf(fi, "%s ", lastName[i]);
            fscanf(fi, "%d\n", &occupants[i]);
            status[i] = TRUE;
            fprintf(fo, "%s was checked into room %d\n", lastName[i], i);
            available = TRUE;
            break;
        }
    if (available == 0)
        fprintf(fo, "Sorry, no room was available for %s\n", lastName[i]);
}
void Checkout(FILE *fi, FILE *fo, int n, char lastName[][30], int status[n])
{
    int rooms = 0;
    char temp[20];
    fscanf(fi, "%s\n", temp);
    for (int i = 0; i < n; i++)
        if (!strcmp(temp, lastName[i]))
        {
            fprintf(fo, "%s was checked out of room %d\n", lastName[i], i);
            status[i] = FALSE;
            strcpy(lastName[i], "");
            rooms = TRUE;
            break;
        }
    if (rooms == 0)
        fprintf(fo, "%s %s\n", "Sorry, there is no occupant named", temp);
}
void Search(FILE *fi, FILE *fo, int n, char lastName[][30], int status[n])
{
    int rooms = 0;
    char temp[20];
    fscanf(fi, "%s\n", temp);
    for (int i = 0; i < n; i++)
        if (!strcmp(temp, lastName[i]))
        {
            fprintf(fo, "%s %s %d\n", temp, "is currently staying in room", i);
            rooms = TRUE;
            break;
        }
    if (!rooms)
        fprintf(fo, "%s %s\n", "Sorry, there is no occupant named", temp);
}

void Printoccupantcy(FILE *fi, FILE *fo, int n, char lastName[][30], int status[n], int occupants[n])
{
    fprintf(fo, "Name \t\tRoom number \t    Number of occupants\n");
    for (int i = 0; i < n; i++)
        if (status[i] == TRUE)
            fprintf(fo, "%-15s %-15d %-20d\n", lastName[i], i, occupants[i]);
}

int main(int argc, char const *argv[])
{
    char c, s[30];
    int n, temp = 0;
    FILE *fi = fopen(filename, "r");
    FILE *fo = fopen(fileout, "w");
    OpenFile();
    fscanf(fi, "%d", &n);
    char lastName[n][30];
    int status[n];
    int occupants[n];
    memset(status, 0, sizeof(status));
    do
    {
        fscanf(fi, "%s ", s);
        if (strcmp(s, "CHECKIN") == 0)
            Checkin(fi, fo, n, lastName, status, occupants);
        if (strcmp(s, "CHECKOUT") == 0)
            Checkout(fi, fo, n, lastName, status);
        if (strcmp(s, "SEARCH") == 0)
            Search(fi, fo, n, lastName, status);
        if (strcmp(s, "PRINTOCCUPANCY") == 0)
            Printoccupantcy(fi, fo, n, lastName, status, occupants);
        temp++;
    } while (temp < n);
    printf("\nData has been saved to the file %s !!!", fileout);
    fclose(fi);
    fclose(fo);
    getch();
    return 0;
}
