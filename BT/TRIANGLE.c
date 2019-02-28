#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    float a,b,c,p,dt,cv;
    printf("Enter 3 numbers: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a >= b + c || b >= a + c || c >= a + b)
        printf("Not a triangle");
    else
    {
        cv = a + b +c;
        p = cv / 2;
        dt=sqrt(p*(p-a)*(p-b)*(p-c));
        printf("Perimeter: %.0f \n",cv);
        printf("Area: %.0f",dt);
    
    }
    getch();
    return 0;
}
