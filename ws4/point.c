#include <stdio.h>

int main(int argc, char const *argv[])
{
	int *pa, *pb;
	int a,b;
	printf("Enter a:");
	scanf("%d", &a);
	printf("Enter b:");
	scanf("%d", &b);
	pa = &a;
	pb = &b;
	*pa = a+b;
	printf("Sum = %d\n", a);
	getch();
    return 0;
}



