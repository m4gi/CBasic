#include <stdio.h>
void maxmin(int n)
{
	int max = 0, min = 9;
	while (n != 0)
	{
		if (max < n % 10)
			max = n % 10;
		if (min > n % 10)
			min = n % 10;
		n = n / 10;
	}
	printf("max=%d,  min=%d", max, min);
}
int main()
{
	int n;
	printf("enter number:");
	scanf("%d", &n);
	maxmin(n);
    getch();
	return 0;
}
