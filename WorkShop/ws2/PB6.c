#include <stdio.h>

int main(int argc, char const *argv[])
{
    int code;
    for(code=0;code<255;code++)
    {
    	printf("%c : %d : %o : %x\n", code, code, code, code);	
	}
    return 0;
}



