#include <stdio.h>
#include <math.h>
int num();
int NT(int n)
{
   int i,m;
   m=sqrt(n);
   if (n<2) return 0;
   for(i=2; i<=m; i++)
   {
       if (n%i==0) return 0;
   }
   return 1;
}
void print()
{
	int i,n;
	n = num();
    for(i=2;i<=n;i++)
    {
    	if(NT(i))
    	{
    		printf("%d ", i);
		}
	}
}
int num()
{
	int n;
	do 
	{
		printf("Enter number: ");
    	scanf("%d", &n);
	} while (n<2);
	return n;
}
int main(int argc, char const *argv[])
{
	print();
    return 0;
}


