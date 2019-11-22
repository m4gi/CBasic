#include <stdio.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    int age;
    char gender;
    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter gender (male(M)/female(F)): ");
    fflush(stdin);
    scanf("%c", &gender);
    gender = toupper(gender);
    if (age >= 35 && age <= 55 && gender == 'M')
    {
        printf("Congratulation! You are eligible for casting your vote.\n");
    }
    else
    {
        printf("Sorry, You are not eligible to caste your vote.\n");
        printf("You would be able to caste your vote after %d year.\n", 18 - age);
    }
    return 0;
}
