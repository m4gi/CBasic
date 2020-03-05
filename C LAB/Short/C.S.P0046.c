#include <stdio.h>

int userChoice()
{
	int choice;
	printf("\n_ _ _ _ _ _ _ _MENU_ _ _ _ _ _ _ _");
	printf("\n1. The first primes");
	printf("\n2. Fibonacci element");
	printf("\n3. Sum of digits");
	printf("\n4. Quit");
	printf("\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
	printf("\n\n Choose an option: ");
	scanf("%d", &choice);
	return choice;
}

int primeNumber(int n)
{
	int i, count;
	if (n == 2)
		return 1;
	for (i = 2; i < n; i++)
	{
		count = 0;
		if (n % i == 0)
		{
			count++;
			break;
		}
	}
	if (count == 0)
	{
		return 1;
	}
	return 0;
}

int checkFibonacci(int n)
{
	int s1 = 0, s2 = 1, s3, count = 0;
	do
	{
		s3 = s1 + s2;
		if (s1 == n)
			return 1;
		s1 = s2;
		s2 = s3;
		count++;
	} while (count != 18);
	return 0;
}

int sumOfDigit(int n)
{
	int sumDigit = 0;
	do
	{
		sumDigit += n % 10;
		n /= 10;
	} while (n > 0);
	return sumDigit;
}

int main()
{
	int choice, n, i, count = 0;
	do
	{
		choice = userChoice();
		switch (choice)
		{
		case 1:
			do
			{
				printf("Number of primes: ");
				scanf("%d", &n);
				if (n < 0 || n > 50)
				{
					printf("Number of primes must be in 0 < n <50");
				}
			} while (n < 0 || n > 50);
			for (i = 0; i <= 100; i++)
			{
				if (primeNumber(i) == 1)
				{
					printf("%d, ", i);
					count++;
				}
				if (n == count)
				{
					break;
				}
			}
			break;
		case 2:
			do
			{
				printf("Number tested: ");
				scanf("%d", &n);
				if (n < 0 || n > 1000)
				{
					printf("Number of primes must be in 0 < n <1000");
				}
			} while (n < 0 || n > 1000);
			if (checkFibonacci(n) == 1)
			{
				printf("\nIt's a Fibonacci term");
			}
			else
			{
				printf("\nIt's not a Fibonacci term");
			}
			break;
		case 3:
			printf("\nEnter an integer: ");
			scanf("%d", &n);
			printf("Sum of digit = %d", sumOfDigit(n));
			break;
		case 4:
			break;
		}
	} while (choice != 4);
	return 0;
}
