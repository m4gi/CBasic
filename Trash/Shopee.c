#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int id = 111, q = 10;
    double price = 10.3215, weight = 0.12321;
    char name[30] = "Tuan";
    printf("\n ...........Shoping table........\n");
    printf("\n%-10s|%10s|%10s|%10s\n", "ID", "name", "price", "weight");
    printf("\n%-10d|%10s|%10.3lf|%10.3lf\n", id, name, price, weight);
    getch();
    return 0;
}

