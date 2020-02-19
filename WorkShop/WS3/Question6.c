#include <stdio.h>

int checkpe(int n)
{
    int i, s=0;
    for(i=1;i<=n-1;i++)
    {
    	if(n%i==0)
    		s+=i;
	}
    return s;
}  
int main(int argc, char const *argv[])
{
    int i,n;
    printf("Input lowest search limit of perfect numbers : ");
    scanf("%d", &i);
    printf("Input highest search limit of perfect numbers : ");
    scanf("%d", &n);
    printf("The perfect numbers between %d to %d are :\n", i, n);
    for(i;i<=n;i++)
    {
        if(checkpe(i)==i)   
        printf("%3d", i);
    }
    getch();
    return 0;
}
 