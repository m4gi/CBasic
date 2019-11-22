#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i = 1, n, sum = 0, d = 0;
	printf("Input number of terms : ");
	scanf("%d", &n);
	printf("\nThe odd numbers are :");
	while (d != n)
	{
		if (i % 2 != 0)
		{
			printf("%d  ", i);
			d += 1;
			sum += i;
		}
		i+=2;
	}
	printf("\nThe Sum of odd Natural Number upto %d terms : %d \n", n, sum);
    getch();
	return 0;
}
