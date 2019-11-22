#include <stdio.h>

void AreaOfCircle()
{
    printf("\n Area Of Circle: \n");
}
void AreaOfRectangle()
{
    printf("\n Area Of Rectangle: \n");   
}
void AreaOfTriangle()
{
    printf("\n Area Of Triangle: \n");
}
int uChoice()
{
    int choice;
    printf("\n 1. Area Of Circle.");
    printf("\n 2. Area Of Rectangle.");
    printf("\n 3. Area Of Triangle.");
    printf("\n 4. Quit!!!\n");
    printf("\nInput [1..4]: ");
    scanf("%d", &choice);
    return choice;
}
int main(int argc, char const *argv[])
{
    int choice;
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            AreaOfCircle();
            break;
        case 2:
            AreaOfRectangle();
            break;
        case 3:
            AreaOfTriangle();
            break;
        default: printf("Input number 1->4.");
        }
    } while (choice>=1 && choice<=3);
    getch();
    return 0;
}
