#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int n, m;
	int a[50];
	int sum = 0;
	int i = 0;
	printf("Enter number:");
	scanf("%d", &n);
	m = n;
	while (n != 0)
	{
		a[i] = n % 10;
		i++;
		n = n / 10;
	}
	for (int j = i - 1; j >= 0; j--)
	{
		sum += pow(a[j], 3);
	}

	if (sum == m)
		printf("%d is  armstrong number.\n ", m);
	else
		printf("%d is not armstrong number.\n ", m);
		getch();
	return 0;
}
