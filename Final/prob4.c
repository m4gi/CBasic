#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i,n,t=1;
    printf("Nhap n:");
    scanf("%d", &n);
    int a[n];
    for (i=0; i<n; i++)
        {
            printf("Nhap vao:");
            scanf("%d", &a[i]);
        }
    for(i=0;i<n;i++)
        if (a[i]>a[i+1])
            {
                t=0;
                break;
            }
        
    if (t==0) printf("mang chua duoc sap xep");
        else printf("mang da duoc sap xep");
    getch();
    return 0;
}
