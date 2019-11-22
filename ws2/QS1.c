#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    if(number%2)
    {
    	printf("%d is odd number", number);
	}
	else
	{
		printf("%d is even number", number);
	}
    return 0;
}



