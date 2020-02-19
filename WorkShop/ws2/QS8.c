#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int sidea, sideb, sidec; //are three sides of a triangle

    printf("Input three sides of triangle: ");
    scanf("%d%d%d", &sidea, &sideb, &sidec);

    if (sidea == sideb && sidea == sidec && sidec == sideb)
    {
        printf("This is an equilateral triangle.\n");
    }
    else if (sidea == sideb || sidea == sidec || sidec == sideb)
    {
        printf("This is an isosceles triangle.\n");
    }
    else
    {
        printf("This is a scalene triangle.\n");
    }
    return 0;
}
