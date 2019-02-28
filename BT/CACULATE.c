#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    char op;
    int a,b,c;
    printf("Enter 1st number: ");
    scanf("%d",&a);
    printf("Enter 2nd number: ");
    scanf("%d",&b);
    printf("Enter operand: ");
    scanf("%s",&op);
    switch(op)
    {
        case '+':c = a + b;
            printf(">> The result of : %d + %d = %d",a,b,c);
            break;
        case '-':c = a - b;
            printf(">> The result of : %d - %d = %d",a,b,c);
            break;
        case '*':c = a * b;
            printf(">> The result of : %d * %d = %d",a,b,c);
            break;
        case '/':c = a / b;
            printf(">> The result of : %d / %d = %d",a,b,c);
            break;
        case '%':c = a % b;
            printf(">> The result of : %d %% %d = %d",a,b,c);
            break;
    }
    getch();
    return 0;
}
