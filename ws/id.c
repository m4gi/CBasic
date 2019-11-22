#include <stdio.h>

int main(int argc, char const *argv[])
{
    char id[10];
    int hour;
    double value, salary;
    printf("Input the Employees ID(Max. 10 chars): ");
    scanf("%s", &id);
    printf("Input the working hrs: ");
    scanf("%d", &hour); 
    printf("Salary amount/hr: ");
    scanf("%lf", &salary); 
    salary = hour * salary; 
    printf("Employees ID = %s\nSalary = U$ %.2lf\n", id,salary);
    getch();
    return 0;
}
