#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 10
#define TRUE 1
#define FALSE 0
int fin;
typedef struct DATA
{
    int ID;
    char Product[20];
    float Price;
    char Category[5];

} DATA;
DATA List[MAX];
int isExist(char filename[])
{
    FILE *fp;
    fp = fopen(filename, "r+");
    if (fp != NULL)
    {
        fclose(fp);
        return 1;
    }
    else
    {
        fclose(fp);
        return 0;
    }
}
void LoadData(char filename[])
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        fflush(stdin);
        printf("Can not open file!!!\n");
        return;
    }
    for (int i = 0; i < MAX; i++)
    {
        fscanf(f, "%d %s %f %s", &List[i].ID, List[i].Product, &List[i].Price, List[i].Category);
        if (List[i].ID == 0 || List[i].Product == NULL)
        {
            fin = i;
            break;
        }
    }
    printf("%s has been properly loaded into the database!\n", filename);
    fclose(f);
}
void AddNew(int x)
{
    int status = TRUE;
    printf("What is the ID number of the item to add?\n");
    scanf("%d", &List[x].ID);
    printf("What is the name of the item to added?\n");
    fflush(stdin);
    scanf("%s", List[x].Product);
    printf("What is the cost of the item to added?\n");
    scanf("%f", &List[x].Price);
    printf("What is the product category of the item to added?\n");
    fflush(stdin);
    scanf("%s", List[x].Category);
    for (int i = 0; i < fin; i++)
    {
        if (List[x].ID == List[i].ID)
        {
            printf("\nSorry, an item with ID number %d is already in database. ", List[x].ID);
            status = FALSE;
            break;
        }
    }
    if (status == TRUE)
    {
        printf("%s has been added in database.\n", List[x].Product);
        fin++;
    }
}
void DeleteItem()
{
    int Local, Value, status = 0;
    printf("What is the ID number of product to delete?\n");
    scanf("%d", &Value);
    for (int i = 0; i < fin; i++)
    {
        if (List[i].ID == Value)
        {
            Local = i;
            status = TRUE;
            break;
        }
    }
    if (status == TRUE)
    {
        printf("\n%s have been deleted from database.", List[Local].Product);
        for (; Local < fin - 1; Local++)
        {
            List[Local] = List[Local + 1];
        }
        fin--;
    }
    else
    {
        printf("\nSorry, there is no item in the database with that ID number.");
    }
}
void ChangeCost()
{
    int Value;
    printf("What is the ID number of item in question?\n");
    scanf("%d", &Value);
    for (int i = 0; i < fin; i++)
    {
        if (List[i].ID == Value)
        {
            printf("What is new price for %s ?\n", List[i].Product);
            scanf("%f", &List[i].Price);
            return;
        }
    }
    printf("Sorry, an item with ID number %d is not in the database.", Value);
}
void SearchItem()
{
    char Item[20];
    int i = 0;
    printf("Which item would you like to search for ?\n");
    scanf("%s", Item);
    for (; i < fin; i++)
    {
        if (strcmp(Item, List[i].Product) == 0)
        {
            printf("Here is the product information: \n");
            printf("%-6d %-6s %-6.2f %-6s", List[i].ID, List[i].Product, List[i].Price, List[i].Category);
            return;
        }
    }
    printf("Sorry, we don't have %s in the store. \n", Item);
}
void DisplayInventory()
{
    printf("%-6s %-10s %-15s %-5s", "ID", "Product", "Price", "Category");
    for (int i = 0; i < fin; i++)
    {
        printf("\n%-6d %-10s %-15.2f %-5s", List[i].ID, List[i].Product, List[i].Price, List[i].Category);
    }
}
void Quit()
{
    char s[5];
    char filename[20];
    FILE *f;
    do
    {
        printf("Would you like to save the change make to database(Y/N)?\n");
        fflush(stdin);
        gets(s);
        s[0] = toupper(s[0]);
    } while (!(s[0] == 'Y') && s[0] == 'N');
    if (strcmp(s, "Y") == 0)
    {
        printf("Please input the file to save the new database: ");
        fflush(stdin);
        gets(filename);
        f = fopen(filename, "w");
        for (int i = 0; i < fin; i++)
            fprintf(f, "%-6d %-10s %-15.2f %-5s\n", List[i].ID, List[i].Product, List[i].Price, List[i].Category);
        fclose(f);
        printf("The file has been saved. Thanks for shopping!\n");
    }
}
int uChoice()
{
    int choice;
    printf("\n\n>>Please make one of the following selection:");
    printf("\n 1) Add new item.");
    printf("\n 2) Delete item");
    printf("\n 3) Change the cost of an item.");
    printf("\n 4) Search for item.");
    printf("\n 5) Display inventory details.");
    printf("\n 6) Quit.");
    printf("\n Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}
int main(int argc, char const *argv[])
{
    int choice;
    char filename[20];
    printf("Welcome to the grocery store!\n");
    do
    {
        printf("Please input the file you'd like to load into stock: ");
        fflush(stdin);
        gets(filename);
        if (isExist(filename) == 0)
            printf("This file doesn't exist. Enter again!\n");
    } while (isExist(filename) == 0);
    LoadData(filename);
    do
    {
        choice = uChoice();
        switch (choice)
        {
        case 1:
            AddNew(fin);
            break;
        case 2:
            DeleteItem();
            break;
        case 3:
            ChangeCost();
            break;
        case 4:
            SearchItem();
            break;
        case 5:
            DisplayInventory();
            break;
        case 6:
            Quit();
            getch();
            exit(1);
        }
    } while (choice >= 1 && choice <= 6);
    return 0;
}