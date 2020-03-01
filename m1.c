//Le Tran Viet Long

#include<stdio.h>
#include<math.h>
#include <conio.h>
int inputNumber(int n)
{
	printf("Enter a positive integer n =  ");
	scanf("%d",&n);
	printf("Please enter a positive integer! \n");
	return n;
}

void checkSquareNumber(int n)
{
	int a;
	a=sqrt(n);
	if(a*a==n){
		printf("%d is a square number %d = %d * %d",n,n,a,a);	
	}
		else{
			printf("%d is not a square number.\n",n);
		}	
}

int main(){
	int n,check;
	do {
		printf("Chek Number Square Program\n");
		n=inputNumber(n);
		checkSquareNumber(n);
		printf("\nPress enter to continue, Esc to exit.\n\n");
		check = getch();
	}while(check!=27);

return 0;
}
