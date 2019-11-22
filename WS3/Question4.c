#include <stdio.h>
#include <math.h>
int prime(int n)
{
   int i,m;
   m = sqrt(n);
   if (n<2) return 0;
   for(i=2; i<=m; i++)
   {
       if (n%i==0) return 0;
   }
   return 1;
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Iput number: ");
    scanf("%d", &n);
    if(prime(n))
    {
        printf("The number %d is a prime number.\n", n);
    } else printf("The number %d is not a prime number. \n", n);
    getch();
    return 0;
}
