#include <stdio.h>      // Khai bao thu vien
#include <conio.h>      // khai bao thu vien

int main(int argc, char const *argv[])    // phan chinh
{
    char st;                              // khai bao bien
    int a;                                // khai bao bien
    float b;                              // khai bao bien
    printf("Enter an int: ");
    scanf("%d",&a);
    printf("Enter an float: ");
    scanf("%f",&b);
    printf("Enter an character: ");
    scanf(" %c",&st);
    printf(">>You Entered:\n");
    printf("%d as an interger;\n%f as an float;\nand \"%c\" as a character.\n",a,b,st);
    getch();
    return 0;
    
}
