#include <stdio.h>
#include <conio.h>

int NT(int n)
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
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (NT(n)) 
        printf("This is a prime number.");
    else
        printf("This is not a prime number.");
    getch();
    return 0;
}
