#include <stdio.h>
#include <math.h>

int prime(int n)
{
   int i;
   if (n<2) return 0;
   for(i=2; i<=n/2; i++)
   {
       if (n%i==0) return 0;
   }
   return 1;
}
int main(int argc, char const *argv[])
{
    int n,i;
    do {
        printf("Enter number bigger than 2: ");
        scanf("%d", &n);
        if(prime(n))
        {
            printf("%d is a prime number\n", n);
        } else 
        printf("%d is not a prime number\n", n);
    } while (n<=2);
    getch();
    return 0;
}
