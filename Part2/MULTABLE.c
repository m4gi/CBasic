#include <stdio.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    int n, i;
    printf("Enter an integer: ");
    scanf("%d",&n);
    i=1;
    do      //thuc hien da roi moi kiem tra
    {
        printf("%d * %d = %d \n", n, i, n*i);
        i++;
    }
    while (!(i>10));
    printf("\n \n");
    while (!(i>10))     // kiem tra dieu kien roi moi thuc hien
    {
        printf("%d * %d = %d \n", n, i, n*i);
        i++;
    }
    getch();
    return 0;
}
