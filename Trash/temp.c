#include <stdio.h>

int main(int argc, char const *argv[])
{
    int t;
    printf("Enter temperature: ");
    scanf("%d", &t);
    if(t<0)
    {
    	printf("Freezing weather");
	} else if (t<10)
			{
				printf("very cold");
			} else if (t<20)
					{
						printf("cold");
					}	else if (t<30)
						{
							printf("normal");
						}	else if (t<40)
							{
								printf("hot");
							}	else printf("very hot");
    return 0;
}



