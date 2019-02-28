#include <stdio.h>
#include <conio.h>
#define PI 3.14

int main(int argc, char const *argv[])
{
    float r,cv,dt,tt;
    printf("Radius of circle: ");
    scanf("%f",&r);
    cv=r*2*PI;
    dt=r*r*PI;
    tt=(4/3)*r*r*r*PI;
    printf("Perimeter of the circle: %.2f\n",cv);
    printf("Area of the circle: %.2f\n",dt);
    printf("Volume of the sphere: %.2f\n",tt);
    getch();
    return 0;
}
