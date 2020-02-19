#include <stdio.h>

int main(int argc, char const *argv[])
{
    int km, fuel;
    float total;
    printf("Input total distance in km:");
    scanf("%d", &km);
    printf("Input total fuel spent in liters:");
    scanf("%d", &fuel);
    total = km /  fuel;
    printf("Average consumption (km/lt) %.3f", total);
    getch();
    return 0;
}


