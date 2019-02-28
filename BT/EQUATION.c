#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    float a,b,c,delta,x1,x2,x;
    printf("Enter a,b,c: ");
    scanf("%f %f %f", &a, &b, &c);
    delta= b*b-4*a*c;
    if (a==0)
    {
        if (b==0)
            if (c==0)
                printf("Phuong trinh co vo so nghiem");
            else 
                printf("Phuong trinh vo nghiem");
        else 
        {
            x = -c/b;
            printf("x = %.2f",x);
        }
    }
    else 
        if (delta > 0)
        {
            x1= (-b+sqrt(delta))/(2*a);
            x2= (-b-sqrt(delta))/(2*a);
            printf("x1 = %.2f \nx2 = %.2f\n",x1,x2);
        }
        else if (delta==0)
        {
            x1 = x2 = -b/(2*a);
            printf("x1 = x2 = %.2f",x1);
        }
            else 
                printf("Phuong trinh vo nghiem");
    getch();
    return 0;
}
