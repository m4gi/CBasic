#include <stdio.h>
#include <conio.h>

int NT(int n)    //kiem tra so nguyen to neu dung tra gia tri ve 1 sai =0
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
    if (NT(n)) // neu dung thi in ra con sai thi in ra dong con lai
        printf("This is a prime number.");
    else
        printf("It isn't prime number.");
    getch();
    return 0;
}
