#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

void InputMx(int mx1[][50], int mx2[][50], int n, int m)
{
    printf("\nInput matrix 1: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("\nMX1[%d][%d] = ", i, j);
            scanf("%d", &mx1[i][j]);
        }
    }
    printf("\nInput matrix 2: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("\nMX2[%d][%d] = ", i, j);
            scanf("%d", &mx2[i][j]);
        }
    }
}

void MultiplyMx(int mx1[][50], int mx2[][50], int mul[][50], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                mul[i][j] += mx1[i][k] * mx2[k][j];
            }
        }
    }
    printf("\nDisplay Multiply of Matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Mul[%d][%d] = %d\t", i, j, mul[i][j]);
        }
        printf("\n");
    }
}
void AddMx(int mx1[][50], int mx2[][50], int add[][50], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            add[i][j] = mx1[i][j] + mx2[i][j];
        }
    }
    printf("\nDisplay Sum of Matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Sum[%d][%d] = %d\t", i, j, add[i][j]);
        }
        printf("\n");
    }
}
void reduction(float a[][50], int size, int pivot, int col)
{
    int i, j;
    float factor;
    factor = a[pivot][col];

    for (i = 0; i < 2 * size; i++)
    {
        a[pivot][i] /= factor;
    }

    for (i = 0; i < size; i++)
    {
        if (i != pivot)
        {
            factor = a[i][col];
            for (j = 0; j < 2 * size; j++)
            {
                a[i][j] = a[i][j] - a[pivot][j] * factor;
            }
        }
    }
}
void InverseMx(int mx1[][50], int mx2[][50], float inv1[][50], float inv2[][50], int n, int m)
{
    int i, j;
    printf("\nInverse of matrix 1: \n");
    for (i = 0; i < 45; i++)
    {
        for (j = 0; j < 50; j++)
        {
            if (j == i + 3)
            {
                inv1[i][j] = 1;
            }
            else
            {
                inv1[i][j] = 0;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            inv1[i][j] = mx1[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        reduction(inv1, n, i, i);
    }
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < m; j++)
        {
            printf("%8.3f", inv1[i][j + 3]);
        }
    }

    printf("\nInverse of matrix 2: \n");
    for (i = 0; i < 50; i++)
    {
        for (j = 0; j < 50; j++)
        {
            if (j == i + 3)
            {
                inv2[i][j] = 1;
            }
            else
            {
                inv2[i][j] = 0;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            inv2[i][j] = mx2[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        reduction(inv2, n, i, i);
    }
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < m; j++)
        {
            printf("%8.3f", inv2[i][j + 3]);
        }
    }
}
void ConvolutionMx(int N[][50], int M[][50], int P[][50])
{

    // find center position of kernel (half of kernel size)
    int kCenterX = 50 / 2;
    int kCenterY = 50 / 2;

    for (int i = 0; i < 50; ++i) // rows
    {
        for (int j = 0; j < 50; ++j) // columns
        {
            for (int m = 0; m < 50; ++m) // kernel rows
            {
                int mm = 50 - 1 - m; // row index

                for (int n = 0; n < 50; ++n) // kernel columns
                {
                    int nn = 50 - 1 - n; // column index

                    // index of input signal, used for checking boundary
                    int ii = i + (m - kCenterY);
                    int jj = j + (n - kCenterX);

                    // ignore input samples which are out of bound
                    if (ii >= 0 && ii < 50 && jj >= 0 && jj < 50)
                        P[i][j] += N[ii][jj] * M[m][n];
                }
            }
        }
    }
}
void SaveFile(int mx1[][50], int mx2[][50], int add[][50], int mul[][50], float inv1[][50], float inv2[][50], int n, int m)
{
    FILE *f = fopen("Save.txt", "w");
    if (f == NULL)
    {
        fflush(stdin);
        printf("Can not open file!!!\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fprintf(f, "Sum[%d][%d] = %d\t", i, j, add[i][j]);
        }
        fprintf(f, "\n");
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fprintf(f, "Mul[%d][%d] = %d\t", i, j, mul[i][j]);
        }
        fprintf(f, "\n");
    }
    int i, j;
    for (i = 0; i < n; i++)
    {
        fprintf(f, "\n");
        for (j = 0; j < m; j++)
        {
            fprintf(f, "%8.3f", inv1[i][j + 3]);
        }
    }
    fprintf(f, "\n");
    for (i = 0; i < n; i++)
    {
        fprintf(f, "\n");
        for (j = 0; j < m; j++)
        {
            fprintf(f, "%8.3f", inv2[i][j + 3]);
        }
    }
    fprintf(f, "\n");
}
int uChoice()
{
    int choice;
    printf("\n=================Menu================\n");
    printf("\n 1- Enter 2 matrices m x n.");
    printf("\n 2- Multiply 2 matrices.");
    printf("\n 3- Add 2 matrices.");
    printf("\n 4- Inverse matrix.");
    printf("\n 5- Convolution 2 matrices (Optional).");
    printf("\n 6- Save the resulting content to a file.");
    printf("\n Other to exit!");
    printf("\nEnter your choice:  ");
    scanf("%d", &choice);
    return choice;
}
int main(int argc, char const *argv[])
{
    int mx1[50][50], mx2[50][50];
    int mul[50][50], add[50][50];
    float inv1[50][50], inv2[50][50];
    int convo[50][50];
    int choice;
    int n, m;
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            printf("\nEnter n x m of Matrix: ");
            scanf("%d%d", &n, &m);
            InputMx(mx1, mx2, n, m);
            break;
        case 2:
            MultiplyMx(mx1, mx2, mul, n, m);
            break;
        case 3:
            AddMx(mx1, mx2, add, n, m);
            break;
        case 4:
            InverseMx(mx1, mx2, inv1, inv2, n, m);
            break;
        case 5:
            ConvolutionMx(mx1, mx2, convo);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    printf("Convo[%d][%d] = %d\t", i, j, convo[i][j]);
                }
                printf("\n");
            }
            break;
        case 6:
            SaveFile(mx1, mx2, add, mul, inv1, inv2, n, m);
            break;
        }
    } while (choice >= 1 && choice <= 6);
    return 0;
}
