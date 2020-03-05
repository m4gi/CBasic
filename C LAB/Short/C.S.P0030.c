/*Addition of odd/even numbers.*/
#include <stdio.h>
#include <conio.h>
void InputA(int *arr, int n)
{
    int i;
    printf("Input elements:\n");
    for (i = 1; i <= n; i++)
    {
        printf("\tElement %d=", i);
        scanf("%d", &arr[i]);
    }
}
void Caculate(int *arr, int n)
{
    int even, odd;
    even = 0;
    odd = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] % 2)
            odd += arr[i];
        else
            even += arr[i];
    }
    printf("Sum of even: %d\n", even);
    printf("Sum of odd: %d\n", odd);
}

int main(int argc, char const *argv[])
{

    int n;
    printf("Sum Even Odd Program\n");
    printf("Enter a number of element n= ");
    scanf("%d", &n);
    int arr[n];
    InputA(arr, n);
    Caculate(arr, n);
    getch();
    return 0;
}
