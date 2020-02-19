#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])

{
	int x, sum, ctr;
	int i, n, m, mm, nn;
	printf("Input the value of x,terms :");
	scanf("%d", &x);
	sum = x;
	m = -1;
	printf("The values of the series: \n");
	printf("%d\n", x);
	for (i = 1; i <= x; i++)
	{
		ctr = (2 * i + 1);
		mm = pow(x, ctr);
		nn = mm * m;
		printf("%d \n", nn);
		sum = sum + nn;
		m *= -1;
	}
	printf("\nThe sum = %d\n", sum);
	return 0;
}
