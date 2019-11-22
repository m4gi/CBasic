#include <stdio.h>

int main(int argc, char const *argv[])
{
    int mark, reward, shirt;
    printf("Your mark:");
    scanf("%d", &mark);
    switch (mark)
    {
        case 1: reward = 1000;
                shirt = 1;
                break;
        case 2: reward = 2000;
                shirt = 2;
                break;
        case 3: reward = 3000;
                shirt = 3;
                break;
        case 4: reward = 4000;
                shirt = 4;
                break;
        case 5: reward = 5000;
                shirt = 5;
                break;
        case 6: reward = 6000;
                shirt = 6;
                break;
        case 7: reward = 7000;
                shirt = 7;
                break;
        case 8: reward = 8000;
                shirt = 8;
                break;
        case 9: reward = 9000;
                shirt = 9;
                break;
        case 10: reward = 10000;
                shirt = 10;
                break;
        default: reward = 0;
                 shirt = 0;
       
    }
    printf("Reward: %d\n Shirt: %d", reward, shirt);
    getch();
    return 0;
}


