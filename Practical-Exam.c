#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 100
#define TRUE 1
#define FALSE 0
int a[max];
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}
int exist(char *filename)
{
    int existed = FALSE;
    FILE *f = fopen(filename, "r");
    if (f != NULL)
    {
        existed = TRUE;
        fclose(f);
    }
    return existed;
}

int writeFile(char *filename)
{
    char c;
    int i = 0;
    int CTRL_Z = -1;
    if (exist(filename) == TRUE)
    {
        printf("File %s already existed. Rewrite? Y/N? :", filename);
        if (toupper(getchar()) == "N")
            return FALSE;
    }
    char line[201];
    int length = 0;
    FILE *f = fopen(filename, "w");
    fflush(stdin);
    do
    {
        if (i == 0)
        {
            printf("Enter your name:");
            gets(line);
            fputs(line, f);
            fputs("\n", f);
        }
        if (i == 1)
        {
            printf("Enter your class:");
            fflush(stdin);
            c = gets(line);
            fputs(line, f);
            fputs("\n", f);
        }
        if (i == 2)
        {
            printf("Enter your university:");
            fflush(stdin);
            gets(line);
            fputs(line, f);
            fputs("\n", f);
        }
        if (i == 3)
        {
            printf("Enter your field:");
            fflush(stdin);
            gets(line);
            fputs(line, f);
            fputs("\n", f);
        }
        if (i == 4)
            break;
        i++;
    } while (c != CTRL_Z);
    fclose(f);
    return TRUE;
}
int printFile(char *filename)
{
    char c;
    if (exist(filename) == FALSE)
    {
        printf("The file %s does not exist.\n", filename);
        return FALSE;
    }
    FILE *f = fopen(filename, "r");
    while ((c = fgetc(f)) != EOF)
        putchar(c);
    fclose(f);
    return TRUE;
}
void myinfo()
{
    char filename[81] = "Information.txt";
    printf("Program for writing then redding a file \n");
    printf("Enter the file name: ");
    fflush(stdin);
    printf("write file:\n");
    if (writeFile(filename) == TRUE)
    {
        printf("Data in the file %s: \n", filename);
        if (printFile(filename) == FALSE)
            printf("File error!!\n");
    }
    else
        printf("Writing file fail!\n", filename);
}
int checkPerfect(int n)
{
    int i, s = 0;
    for (i = 1; i <= n - 1; i++)
    {
        if (n % i == 0)
            s += i;
    }
    return s;
}
void displayPerfect(int limit)
{
    int i;
    printf("Perfect number from 1 to %d : ", limit);
    for (i = 1; i < limit; i++)
    {
        if (checkPerfect(i) == i)
            printf("%5d", i);
    }
}
void writePerfect()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    displayPerfect(n);
}
long factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}
double talkingSum(int n)
{
    int i;
    long m;
    double s = 0;
    for (i = 1; i <= n; i++)
    {
        m = factorial(i);
        s += (m / i);
    }
    return s;
}
void calulate()
{
    int n;
    double s;
    printf("Enter number: ");
    scanf("%d", &n);
    s = talkingSum(n);
    printf("Result of sum: %.3lf", s);
}
void talkingSumP(int n, double *rs)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        *rs += 1 / (float)(i);
    }
}
void calulateP()
{
    int n;
    double rs;
    rs = 0;
    printf("Enter number:");
    scanf("%d", &n);
    talkingSumP(n, &rs);
    printf("Result of sum: %lf", rs);
}
void enterMArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("A[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
void enterRArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = 20 + rand() % (40 + 1 - 20);
    }
}
void enterarray()
{
    int n;
    printf("Enter number element of array: ");
    scanf("%d", &n);
    printf("Enter manual array \n");
    enterMArray(a, n);
}
void enterarrayR()
{
    int n;
    printf("Enter number element of array: ");
    scanf("%d", &n);

    enterRArray(a, n);
}
void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("A[%d] = %d\n", i, a[i]);
    }
}
void displayA()
{
    int n;
    printf("Enter number:");
    scanf("%d", &n);
    display(a, n);
}
int findX(int a[], int n, int X)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == X)
            return i;
    }
    return -1;
}
void finda()
{
    int n, x, pos;
    printf("Enter size of array : ");
    scanf("%d", &n);
    printf("Enter X: ");
    scanf("%d", &x);
    pos = findX(a, n, x);
    if (pos == -1)
    {
        printf("Can't find X in array!!");
    }
    else
        printf("%d has in array.");
}
void sortArray(int a[], int n)
{
    quickSort(a, 0, n);
}
void sorte()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    sortArray(a, n);
}
int removeX(int a[], int n, int position)
{
    a[position] = 0;
}
void removea()
{
    int n,x,pos;
    printf("Enter X want to remove: ");
    scanf("%d", &x);
    printf("Enter size of array : ");
    scanf("%d", &n);
    pos = findX(a,n,x);
    removeX(a,n,pos);
}
int uChoice()
{
    int choice;
    printf("\n=================MENU================\n");
    printf("\n Press 1. Student Information.");
    printf("\n Press 2. Calculate Sum");
    printf("\n Press 3. Print out perfect number from 1 to limit.");
    printf("\n Press 4. Using pointer to calcuate Sum.");
    printf("\n Press 5. Enter a manual array.");
    printf("\n Press 6. Enter a random array from 20 to 40.");
    printf("\n Press 7. Display an array.");
    printf("\n Press 8. Find X value in Array, return its index.");
    printf("\n Press 9. Sort an arrat and display them.");
    printf("\n Press 10. Remove X value un an array.");
    printf("\n Press 11. Exit.\n");
    printf("\n=====================================\n");
    printf("\nInput [1..3]:  ");
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
            myinfo();
            break;
        case 2:
            calulate();
            break;
        case 3:
            writePerfect();
            break;
        case 4:
            calulateP();
            break;
        case 5:
            enterarray();
            break;
        case 6:
            enterarrayR();
            break;
        case 7:
            displayA();
            break;
        case 8:
            finda();
            break;
        case 9:
            sorte();
            break;
        case 10:
            removea();
            break;
        default: exit(1);
        }
    } while (choice >= 1 && choice <= 10);
    getch();
    return 0;
}