#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char a[100];
    char b[100];
    char c[100];
    int i, j;
    i = 0;
    j = 0;
    printf("nhap vao: ");
    scanf("%s", &a);
    printf("nhap vao: ");
    scanf("%s", &b);
    while (a[i] != '\0')
    {
        c[i] = a[i];
        i++;
    }
    c[i] = ' ';
    i++;
    while (b[j] != '\0')
    {
        c[i] = b[j];
        j++;
        i++;
    }
    c[i] = '\0';
    printf("Xau da duoc noi: %s", c);
    getch();
    return 0;
}
