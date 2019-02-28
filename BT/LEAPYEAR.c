#include <stdio.h>

int main(int argc, char const *argv[])
{
    int day,month,year,bien;
    printf("Nhap thang/nam:");
    scanf("%d %d", &month, &year);
    if (month > 0 && month <= 12)
    {  
        if (month >= 1 && month <= 3)
            printf("Quy I\n");
        else if (month >= 4 && month <= 6)
                printf("Quy II\n");
            else if (month >= 7 && month <= 9)
                    printf("Quy III\n");
                else printf("Quy IV\n");
        switch(month)
        {
            case 1: 
                printf("31 ngay\n");
                break;
            case 2:
                if ((year % 4 == 0) && (year % 100 != 0))
                    printf("29 ngay\n");
                else 
                    printf("28 ngay\n");
                    break;
            case 3: 
                printf("31 ngay\n");
                break;
            case 4: 
                printf("30 ngay\n");
                break;
            case 5: 
                printf("31 ngay\n");
                break;
            case 6: 
                printf("30 ngay\n");
                break;
            case 7: 
                printf("31 ngay\n");
                break;
            case 8: 
                printf("31 ngay\n");
                break;
            case 9: 
                printf("30 ngay\n");
                break;
            case 10: 
                printf("31 ngay\n");
                break;
            case 11: 
                printf("30 ngay\n");
                break;
            case 12: 
                printf("31 ngay\n");
                break;
        }
    }
    else printf("Thang khong hop le\n");
    getch();
    return 0;
}