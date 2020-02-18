#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define PI 3.1415926535
#define INCH 0.0000157828282828
void calculatingfuel()
{
    int minutes;
    float speed, gallon;
    printf("\nHow many minutes did you drive?\n");
    scanf("%d", &minutes);
    printf("What was the average speed of the car during that time?\n");
    scanf("%f", &speed);
    printf("How many gallon of gas did your car use?\n");
    scanf("%f", &gallon);
    printf("Your car averaged %.2f miles per gallon.\n", speed / 60 * minutes / gallon);
}
void calculatingdistance()
{
    float radius;
    int revolutions;
    printf("\nWhat is the radius of your tires, in inches?\n");
    scanf("%f", &radius);
    printf("How many revolutions did your car's tires make?\n");
    scanf("%d", &revolutions);
    printf("Your car traveled %.2f miles.\n", PI * 2 * radius * revolutions * INCH);
}
void RevisedFuelEconomy()
{
    float radius, gallons;
    int revolutions;
    printf("\nWhat is the radius of your tires, in inches?\n");
    scanf("%f", &radius);
    printf("How many revolutions did your car's tires make?\n");
    scanf("%d", &revolutions);
    printf("How many gallons of gas did your car use?\n");
    scanf("%f", &gallons);
    printf("Your car averaged %.2f miles per gallon.\n", PI * 2 * radius * revolutions * INCH / gallons);
}
int uChoice()
{
    int choice;
    printf("\n1 - Calculating Fuel Economy\n");
    printf("2 - Calculating Distance Traveled\n");
    printf("3 - Revised Fuel Economy Calculation");
    printf("\nChoice feature:  ");
    scanf("%d", &choice);
    return choice;
}
int main(int argc, char const *argv[])
{
    int choice;
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            calculatingfuel();
            break;
        case 2:
            calculatingdistance();
            break;
        case 3:
            RevisedFuelEconomy();
            break;
        default:
            exit(1);
        }
    } while (choice >= 1 && choice <= 3);
    getch();
    return 0;
}