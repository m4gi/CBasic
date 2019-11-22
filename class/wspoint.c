#include <stdio.h>
#include <conio.h>


float sum(int n)
{
    int i;
    float s=1;
    for(i=2;i<=n;i++)
    {
        s += (float)1/i;
    }
    return s;
}
void sump(int n)
{
    float *ptr;
    int *p;
    float rs = 1;
    int i;
    ptr = &rs;
    for ( i = 1; i <= n; i++)
    {
        *ptr += 1/(float)i;
    }
    printf("Sum of number wihtout pointer: %f", *ptr);
}
int uChoice()
{
    int choice;
    printf("\n=================MENU================\n");
    printf("\n Press 1. Sum wihtout pointer.");
    printf("\n Press 2. Sum with pointer.");
    printf("\n Press 3. Check prime.");
    printf("\n Press 4. Display prime number from A to B.");
    printf("\n Other. Quit!!!\n");
    printf("\n=====================================\n");
    scanf("%d", &choice);
    return choice;
}
void runs()
{
    int a;
    float rs;
    printf("Input number: ");
    scanf("%d", &a);
    rs = sum(a);
    printf("Sum of number wihtout pointer: %f", rs);
}
void runsp()
{
    int a;
    float rs; 
    printf("Input number: ");
    scanf("%d", &a);
    sump(a);
}
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
void check()
{
    int n;
    printf("Iput number: ");
    scanf("%d", &n);
    if(prime(n))
    {
        printf("The number %d is a prime number.\n", n);
    } else printf("The number %d is not a prime number. \n", n);
}
void display()
{
    int n,i;
    printf("Iput number a & b: ");
    scanf("%d%d",&i, &n);
    printf("Display prime numbe: \n");
    for(i;i<=n;i++)
    {
        if(prime(i)) printf("%3d", i);
    }
}
int main(int argc, char const *argv[])
{
    int choice;
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            runs();
            break;
        case 2:
            runsp();
            break;
        case 3:
            check();
            break;
        case 4:
            display();
        }
    } while (choice >= 1 && choice <= 2);
    getch();
    return 0;
}