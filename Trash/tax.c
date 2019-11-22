#include <stdio.h>
#define pa  9000000
#define pd  3600000
int main(int argc, char const *argv[])
{
    long long tf,ti,in,it;
    int n;
    printf("Your income of this year: ");
    scanf("%lld", &in);
    printf("Number of dependent: ");
    scanf("%d", &n);
    tf = 12*(pa + n*pd);
    if(in>tf) 
    {
        ti =in - tf;
    }   else ti = 0;
    printf("Tax-free income: %lld\n", tf);
    printf("Taxable income: %lld\n", ti);
    if(ti<=0)
    {
        it = 0;
    } else if(ti<=5000000)
    
    {
        it = ti*5/100;
    } else if(ti<=10000000)
        {
            it = (ti*10/100) - 250000;
        }   else if (ti<=18000000)
            {
                it = (ti*15/100) - 750000;
            }   else it = (ti*20/100) - 1650000;

    printf("Income tax: %lld\n", it);
    getch();
    return 0;
}
