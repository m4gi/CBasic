#include <stdio.h> 
#include <math.h>
int checkam(int n)
{
    int i, s=0;
    while(n!=0)
    {
        i = n % 10;
        n /= 10;
        i = pow(i,3);
        s+=i;
    }
    return s;
}
int checkpe(int n)
{
    int i, s=0;
    for(i=1;i<=n-1;i++)
    {
    	if(n%i==0)
    		s+=i;
	}
    return s;
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Input number: ");
    scanf("%d", &n);
    if(checkam(n)==n)
    {
        printf("The %d is an Armstrong number.\n", n);
    } else printf("The %d is not an Armstrong number.\n", n);
    if(checkpe(n)==n)
	{
		printf("%d is a perfect number", n);
	} else printf("%d is not perfect number", n);
    getch();
    return 0;
}
