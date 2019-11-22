#include <stdio.h>

int main(int argc, char const *argv[])
{
    char s[10];
    printf("Enter: ");
    scanf("%[^\n]", &s);
    printf("%s",s);
    getchar();
    getchar();
    return 0;
}
