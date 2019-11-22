#include <stdio.h>
int sumdigit(int n)
{
	int s, rem;
	while(n>0)
	{
		rem = n % 10;
		s+=rem;
		n/=10;
	}
	return s;
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number:");
    scanf("%d", &n);
    printf("Sum = %d", sumdigit(n));
	getch();
    return 0;
}



