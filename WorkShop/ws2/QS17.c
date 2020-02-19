#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i,n,s=0;
    printf("Enter number: ");
    scanf("%d", &n);
    for(i=1;i<=n-1;i++)
    {
    	if(n%i==0)
    		s+=i;
	}
	if(s==n)
	{
		printf("N is a perfect number");
	} else printf("N is not perfect number");
    return 0;
}



