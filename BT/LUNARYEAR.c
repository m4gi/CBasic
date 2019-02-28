#include <stdio.h>
 
int main(int argc, char const *argv[])
{
    unsigned year;
    char  can[][5] = {"Giap", "At", "Binh", "Dinh", "Mau", "Ky", "Canh", "Tan", "Nham", "Quy"};
    char  chi[][5] = {"Ty", "Suu", "Dan", "Meo", "Thin", "Ty", "Ngo", "Mao", "Than", "Dau", "Tuat", "Hoi"};
    printf("Enter year: ");
    scanf("%d", &year);
    if (year > 100)
        printf("%s %s", can[(year+6)%10], chi[(year+8)%12]);
    else printf("Invalid year.");  
    getch();
    return 0;
}