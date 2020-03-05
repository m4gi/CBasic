#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>

int userChoice()
{
	int choice;
	printf("\n_ _ _ _ _ _ _ _ _ _ _MENU_ _ _ _ _ _ _ _ _ _ _\n");
	printf("1. Convert binary number to decimal number\n");
	printf("2. Convert octal number to decimal number\n");
	printf("3. Convert hexadecimal number to decimal number\n");
	printf("4. Exit");
	printf("\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n");
	printf("Enter your choice: ");
	scanf("%c", &choice);
	return choice;
}

int hexToDec(char n[20])
{
	int x, i;
	int total;
	x = strlen(n);
	x--;
	int tem;
	for (i = 0; n[i] != '\0'; i++)
	{
		if (n[i] >= '0' && n[i] <= '9')
		{
			tem = n[i] - 48;
		}
		else if (n[i] >= 'a' && n[i] <= 'f')
		{
			tem = n[i] - 97 + 10;
		}
		else if (n[i] >= 'A' && n[i] <= 'F')
		{
			tem = n[i] - 65 + 10;
		}
		else
		{
			total = 0;
			x--;
			continue;
		}
		total = total + tem * pow(16, x);
		x--;
	}
	return total;
}
int octToDec(char n[20])
{
	int x, i;
	int total;
	x = strlen(n);
	x--;
	int tem;
	for (i = 0; n[i] != '\0'; i++)
	{
		if (n[i] >= '0' && n[i] <= '7')
		{
			tem = n[i] - 48;
		}
		else
		{
			total = 0;
			x--;
			continue;
		}
		total += tem * pow(8, x);
		x--;
	}
	return total;
}
int binToDec(char n[32])
{
	int x, i;
	int total;
	x = strlen(n);
	x--;
	int tem;
	for (i = 0; n[i] != '\0'; i++)
	{
		if (n[i] == '0' || n[i] == '1')
		{
			tem = n[i] - 48;
		}
		else
		{
			total = 0;
			x--;
			continue;
		}
		total += tem * pow(2, x);
		x--;
	}
	return total;
}
int binDec()
{
	char number[32];
	printf("Enter binary number: ");
	scanf("%s", &number);
	return binToDec(number);
}
int octDec()
{
	char number[20];
	printf("Enter octal number: ");
	scanf("%s", &number);
	return octToDec(number);
}
int hexDec()
{
	char number[20];
	printf("Enter hexadecimal number: ");
	scanf("%s", &number);
	return hexToDec(number);
}

int main()
{
	int choice;
	int number;
	do
	{
		fflush(stdin);
		choice = userChoice();
		switch (choice)
		{
		case '1':
			number = binDec();
			break;
		case '2':
			number = octDec();
			break;
		case '3':
			number = hexDec();
			break;
		case '4':
			break;
		}
		printf("Decimal number is : %d", number);
	} while (choice != '4');

	return 0;
}
