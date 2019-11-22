    #include <stdio.h>

    int main(int argc, char const *argv[])
    {
        int c1, c2, t, d;
        printf("Enter c1:");
        scanf("%d", &c1);
        printf("Enter c2:");
        scanf("%d", &c2);
        if (c1 > c2)
        {
            t = c1;
            c1 = c2;
            c2 = t;
        }
        d = c2 - c1;
        printf("d = %d\n", d);
        for (d = c1; d < c2; d++)
        {
            printf("%5c, %5d, %5o, %5X\n", d, d, d, d);
        }
        getch();
        return 0;
    }
