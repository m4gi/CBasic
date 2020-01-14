#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define fio "Products.txt"
#define fbin "Products.dat"

typedef struct products
{
  char Id[50], name[50];
  int quantity; // so luong
  double cost;  // gia
} product;

void input(product prd[], int *n);
void writeBin(product prd[], int n);
void write(product prd[], int n);

void sort_cost(product prd[], int n);

void readBin(product prd[], int *n);
void output(product prd[], int n);

void search_id(product prd[], int n, char id[]);
void search_name(product prd[], int n, char name[]);
void search(product prd[], int n);

int main()
{
  product prd[50];
  int n;

  int select;
  do
  {
    printf("Products:\n-----------------\n");
    printf("1: input\n2: read and sort by cost\n3: Search\n4: exit\n");
    printf("Enter the number to work: ");
    scanf("%d", &select);
    switch (select)
    {
    case 1:
    {
      printf("1: INPUT\n");
      input(prd, &n);
      write(prd, n);
      break;
    }
    case 2:
    {
      printf("2: READ AND SORT BY COST\n");
      printf("Befor sort:\n--------------\n");
      readBin(prd, &n);
      output(prd, n);
      sort_cost(prd, n);
      write(prd, n);
      printf("After sort:\n--------------\n");
      readBin(prd, &n);
      output(prd, n);
      break;
    }
    case 3:
    {
      printf("SEARCH\n");
      search(prd, n);
      break;
    }
    case 4:
      return 0;
    default:
      printf("Error select !");
      break;
    }
  } while (select != 4);
  return 0;
}

void input(product prd[], int *n)
{
  int i;
  char s[50];
  printf("Enter the number of products: ");
  scanf("%d", n);
  gets(s);
  printf("n");
  for (i = 0; i < (*n); i++)
  {
    printf("Enter the Id of products %d : ", i + 1);
    gets(prd[i].Id);
    printf("\tEnter the nam of products %d : ", i + 1);
    gets(prd[i].name);
    printf("\tEnter the quantity of products %d : ", i + 1);
    scanf("%d", &prd[i].quantity);
    printf("\tEnter the cost of products %d : ", i + 1);
    scanf("%lf", &prd[i].cost);
    gets(s);
  }
}

void writeBin(product prd[], int n)
{
  FILE *f = fopen(fbin, "wb");
  ;
  int i;
  if (f == NULL)
    printf("Error load file");
  else
    fwrite(prd, sizeof(product), n, f);
  fclose(f);
}

void write(product prd[], int n)
{
  int i;
  FILE *f = fopen(fio, "w");
  if (f == NULL)
    printf("Error load file");
  fprintf(f, "%-10s %-15s %-10s %-10s\n", "Id", "Name", "Quantity", "Cost");
  for (i = 0; i < n; i++)
    fprintf(f, "%-10s %-15s %-10d %-10.2lf\n", prd[i].Id, prd[i].name, prd[i].quantity, prd[i].cost);
  fclose(f);
  writeBin(prd, n);
  printf("input and write success to file!n");
}

void sort_cost(product prd[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (prd[i].cost > prd[j].cost)
      {
        product temp = prd[i];
        prd[i] = prd[j];
        prd[j] = temp;
      }
    }
  }
}

void output(product prd[], int n)
{
  int i;
  printf("%-10s %-10s %-15s %-10s %-10s\n", "Order", "Id", "Name", "Quantity", "Cost");
  for (i = 0; i < n; i++)
    printf("%-10d %-10s %-15s %-10d %-10.2lf\n", i + 1, prd[i].Id, prd[i].name, prd[i].quantity, prd[i].cost);
}

void readBin(product prd[], int *n)
{
  FILE *f = fopen(fbin, "rb");
  fseek(f, 0, SEEK_END);                   //Nhay ve cuoi file, di chuyen di 0 vi tri
  (*n) = (ftell(f) + 1) / sizeof(product); //ftell(); tra ve vi tri hien tai cua con tro
  // SEEK_CUR: di chuyen bat dau tu vi tri hien tai cua con tro, chi dung trong fseek()
  fseek(f, 0, SEEK_SET); //Nhay ve dau file, di chuyen di 0 vi tri
  fread(prd, sizeof(product), (*n), f);
  fclose(f);
}

void search_id(product prd[], int n, char id[])
{
  int i, check = 0;
  for (i = 0; i < n; i++)
  {
    if (strcmp(id, prd[i].Id) == 0)
    {
      check = 1;
      printf("%-10s %-10s %-15s %-10s %-10s\n", "Order", "Id", "Name", "Quantity", "Cost");
      printf("%-10d %-10s %-15s %-10d %-10.2lf\n", i + 1, prd[i].Id, prd[i].name, prd[i].quantity, prd[i].cost);
      break;
    }
    if (check == 0 && i == n - 1)
      printf("Not found product have Id is %s !\n", id);
  }
}

void search_name(product prd[], int n, char name[])
{
  int i, check = 0;
  for (i = 0; i < n; i++)
  {
    if (strcmp(name, prd[i].name) == 0)
    {
      check = 1;
      printf("%-10s %-10s %-15s %-10s %-10s\n", "Order", "Id", "Name", "Quantity", "Cost");
      printf("%-10d %-10s %-15s %-10d %-10.2lf\n", i + 1, prd[i].Id, prd[i].name, prd[i].quantity, prd[i].cost);
      break;
    }
    if (check == 0 && i == n - 1)
      printf("Not found product have name is %s !\n", name);
  }
}

void search(product prd[], int n)
{
  int select;
  char s[50];
  do
  {
    printf("\t1: Id\n\t2: Name\n\t3: exit search\nEnter the type you want search: ");
    scanf("%d", &select);
    gets(s);
    switch (select)
    {
    case 1:
    {
      printf("Enter Id want search: ");
      char id[50];
      gets(id);
      search_id(prd, n, id);
      break;
    }
    case 2:
    {
      printf("Enter name want search: ");
      char name[50];
      gets(name);
      search_name(prd, n, name);
      break;
    }
    case 3:
      return;
    default:
      printf("Error select !");
      break;
    }
  } while (select != 3);
}