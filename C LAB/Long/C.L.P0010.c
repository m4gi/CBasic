#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct DATA
{
    char key[100];
    char variable[100];
    int time;
} DATA;
DATA List[20];
int Find(char key[], int *pos)
{
    int n = pos;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(List[i].key, key) == 0)
            return i;
    }
    return -1;
}
void Delete(int vt, int *pos)
{
    int n = pos;
    for (int i = vt; i < n - 1; i++)
    {
        List[i] = List[i + 1];
    }
}
void StoreData(int *pos)
{
    printf("\nEnter your key: ");
    fflush(stdin);
    scanf("%s", List[*pos].key);
    int vt = Find(List[*pos].key, *pos);
    printf("\nEnter your variable: ");
    fflush(stdin);
    gets(List[*pos].variable);
    printf("\nEnter expire time: ");
    scanf("%d", &List[*pos].time);
    if (List[*pos].time > 0 && List[*pos].time < 2592000 && vt < 0)
    {
        printf("\nStored data successfully with key '%s', using on-the-fly compression expire time is %d seconds", List[*pos].key, List[*pos].time);
    }
    else
        printf("\nInvalid Exprire Time or Duplicated Key!");
    *pos += 1;
}
void Retrieve(int *pos)
{
    char ch[100];
    printf("\nEnter your key: ");
    fflush(stdin);
    gets(ch);
    int vt = Find(ch, *pos);
    if (vt >= 0)
    {
        printf("\nYour data is: %s", List[vt].variable);
    }
    else
        printf("\nThis key does't belong to database!");
}
void DeleteItems(int *pos)
{
    char ch[100];
    int n;
    printf("\nEnter your key: ");
    fflush(stdin);
    gets(ch);
    int vt = Find(ch, *pos);
    if (vt >= 0)
    {
        Delete(vt, *pos);
        printf("Delete success.");
    }
    else
        printf("\nThis key does't belong to database!");
    *pos -= 1;
}
int uChoice()
{
    int choice;
    printf("\n=================Memcache================\n");
    printf("\n 1- Store data.");
    printf("\n 2- Retrieve item.");
    printf("\n 3- Delete Items.");
    printf("\n 4- Flush all existing items.");
    printf("\n 5- Exit the program.");
    printf("\nEnter your choice:  ");
    scanf("%d", &choice);
    return choice;
}
int main(int argc, char const *argv[])
{

    int choice, pos = 0;
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            StoreData(&pos);
            break;
        case 2:
            Retrieve(&pos);
            break;
        case 3:
            DeleteItems(&pos);
            break;
        case 4:
            memset(List, 0, sizeof(List));
            printf("\nSucess!");
            break;
        case 5:
            printf("\nExited!");
            getch();
            exit(1);
        }
    } while (choice >= 1 && choice <= 4);
    return 0;
}
