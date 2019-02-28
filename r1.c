#include <stdio.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    int s;
    printf("nhap so giay:");
    scanf("%d",&s);
    if (s>0 && s<89366)
    printf("%02d:%02d:%02d",s/3600,s%3600/60,s%3600%60);
    else 
        printf("thoi gian khong phu hop hoac vuot qua gioi han");
    getch();
    return 0;
}
