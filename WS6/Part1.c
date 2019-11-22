#include <stdio.h>

int checkCanadianSIN(int n)
{
    int N[10];
    int C[12];
    int T1, T2, T3, total;
    int i, result = 0;
    if (n > 0)
    {
        for (i = 9; i > 0; i--)
        {
            N[i] = n % 10;
            n = n / 10;
        }
        C[1] = C[5] = N[2];
        C[2] = C[6] = N[4];
        C[3] = C[7] = N[6];
        C[4] = C[8] = N[8];
        C[9] = 2 * C[1];
        C[10] = 2 * C[2];
        C[11] = 2 * C[3];
        C[12] = 2 * C[4];
        T1 = C[9] / 10 + C[9] % 10 + C[10] / 10 + C[10] % 10 + C[11] / 10 + C[11] % 10 + C[12] / 10 + C[12] % 10;
        T2 = N[1] + N[3] + N[5] + N[7];
        total = T1 + T2;
        T3 = (total / 10 + 1) * 10;
        if (T3 - total == N[9])
            result = 1;
    }
    return result;
}
int main(int argc, char const *argv[])
{
    int n = 193456787;
    if (checkCanadianSIN(n) == 1)
        puts("Valid");
    else
        puts("Invalid");
    getch();
    return 0;
}
