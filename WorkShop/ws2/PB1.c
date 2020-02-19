#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int a, b, c;
    char op;
    printf("Enter 1st number: ");
    scanf("%d", &a);
    printf("Enter 2nd number: ");
    scanf("%d", &b);
    printf("Enter operand: ");
    fflush(stdin);
    scanf("%c", &op);
    switch (op)
    {
    case '+':
        c = a + b;
        printf("The result of: %d + %d = %d", a, b, c);
        break;
    case '-':
        c = a - b;
        printf("The result of: %d - %d = %d", a, b, c);
        break;
    case '*':
        c = a * b;
        printf("The result of: %d x %d = %d", a, b, c);
        break;
    case '/':
        if(b!=0)
        {
            c = a / b;
            printf("The result of: %d / %d = %d", a, b, c);
            break;
        } else printf("Can't div for 0");
    }
    return 0;
}

