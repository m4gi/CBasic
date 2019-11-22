#include <stdio.h>
long sum(int n)
{
	long i=1,j,rs=0,odd=1;
	while(i<=n)
	{
		rs+=odd;
		odd+=2;
		i++;
	}
	return rs;
}
int main(int argc, char const *argv[])
{
    int n,rq;
    int *p;
    printf("Enter number:");
    scanf("%d", &n);
    p = &n;
    rq = sum(n);
    printf("Sum = %ld", rq);
    getch();
    return 0;
}



