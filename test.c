#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
char *filename = "D:\\program.txt";
char ch[10];
int turn = 0;
typedef struct Highscore
{
	char nameg[10];
	int scoreg;
} Highscore;
enum state
{
	MENU,
	GAME,
	GAMEOVER,
	INFO
} state; //enum chua cac ham co dinh trong chuong trinh
int ran[1000], moi = 12006, dk = 0;
int vx = 1, vy = 0; //vx,vy bien vi tri dinh huong di chuyen
int dai, score = 0;
char m, c;
Highscore hs[5];
void sort_score(Highscore hs[], int turn);	
void output(Highscore hs[], int n);
void sort_score(Highscore hs[], int turn)
{
  int i, j;
  for (i = 0; i < 5 - 1; i++)
  {
    for (j = i + 1; j < 5; j++)
    {
      if (hs[i].scoreg < hs[j].scoreg)
      {
        Highscore temp = hs[i];
        hs[i] = hs[j];
        hs[j] = temp;
      }
    }
  }
}
void output(Highscore hs[], int n){
    int i;
    printf("%-15s %-10s\n", "Name","Score");
    for (i = 0; i < n; i++)
        printf("%-15s %-10d\n", hs[i].nameg, hs[i].scoreg);
}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
int random(int a, int b)
{
	return a + rand() % (b - a + 1);
}
void indiem()
{
	gotoxy(6, 00);
	printf("%d", score);
}
void info();
void info()
{

	char enter;
	FILE *fptr;
	fptr = fopen(filename, "a+");

	printf("Enter name(<=10 char): ");
	gets(hs[turn].nameg);

	fclose(fptr);
	printf("enter to ctn!!!");
	enter = getch();
	if (enter == 13)
	{
		system("cls");
		state = GAME;
		game();
	}
}
void game();
void randommoi()
{
	int kt = 0, i; //kt -> bien kiem tra moi trung vs ran hay ko
	for (;;)
	{
		moi = 10000 + random(6, 75) * 100; //ham random moi gioi han x tu vi tri 6-75
		moi += random(4, 22);			   //ham random moi gioi han y tu vi tri 2-22
		for (i = 0; i < dai; i++)
		{
			if (moi == ran[i])
				kt++;
		}
		if (kt == 0)
			break;
	}
}
int getX(int a)
{
	return (a - 10000) / 100;
}
int getY(int a)
{
	return a % 100;
}
void hamran()
{ //khoi tao ham ran toa do (8,10)
	dai = 12;
	ran[0] = 10810;
	ran[1] = 10811;
	ran[2] = 10812;
	ran[3] = 10813;
	ran[4] = 10814;
	ran[5] = 10815;
	ran[6] = 10816;
	ran[7] = 10817;
	ran[8] = 10818;
	ran[9] = 10819;
	ran[10] = 10820;
	ran[11] = 10821;
}
void gotoxy(int x, int y);
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = {x, y};
	SetConsoleCursorPosition(h, c);
}
void contro(int vt, int vtd);
void contro(int vt, int vtd) //tao con tro lua chon
{
	if (vt == 1)
	{
		if (vtd == 2)
		{
			gotoxy(22, 4);
			printf("  ");
			gotoxy(47, 4);
			printf("  ");
		}
		gotoxy(22, 3);
		printf(">>");
		gotoxy(47, 3);
		printf("<<");
	}
	if (vt == 2)
	{
		if (vtd == 1)
		{
			gotoxy(22, 3);
			printf("  ");
			gotoxy(47, 3);
			printf("  ");
		}
		if (vtd == 3)
		{
			gotoxy(22, 5);
			printf("  ");
			gotoxy(47, 5);
			printf("  ");
		}
		gotoxy(22, 4);
		printf(">>");
		gotoxy(47, 4);
		printf("<<");
	}
	if (vt == 3)
	{
		if (vtd == 2)
		{
			gotoxy(22, 4);
			printf("  ");
			gotoxy(47, 4);
			printf("  ");
		}
		if (vtd == 4)
		{
			gotoxy(22, 6);
			printf("  ");
			gotoxy(47, 6);
			printf("  ");
		}
		gotoxy(22, 5);
		printf(">>");
		gotoxy(47, 5);
		printf("<<");
	}
	if (vt == 4)
	{
		if (vtd == 3)
		{
			gotoxy(22, 5);
			printf("  ");
			gotoxy(47, 5);
			printf("  ");
		}
		gotoxy(22, 6);
		printf("<<");
		gotoxy(47, 6);
		printf(">>");
	}
}
void box()
{ //tao ham box -> khung hoat dong
	int i = 0, j = 0;
	for (i; i < 80; i++)
	{
		if (i == 0)
		{
			printf("%c", 201);
		}
		else if (i == 79)
		{
			printf("%c", 187);
		}
		else
			printf("%c", 205);
	}
	for (j; j < 25; j++)
	{
		printf("\n");
		for (i = 0; i < 41; i++)
		{
			if (i == 0 || i == 40)
			{
				printf("%c", 186);
			}
			else
				printf("  ");
		}
	}
	printf("\n");
	for (i = 0; i < 80; i++)
	{
		if (i == 0)
		{
			printf("%c", 200);
		}
		else if (i == 79)
		{
			printf("%c", 188);
		}
		else
			printf("%c", 205);
	}
	printf("\n");
}

void menu()
{
	system("cls");
	int vt = 1, vtd = 0;
	gotoxy(27, 1);
	printf("GAME RAN SAN MOI");
	gotoxy(32, 3);
	printf("choi");
	gotoxy(30, 4);
	printf("huong dan");
	gotoxy(32, 5);
	printf("thoat");
	gotoxy(30, 6);
	printf("thong tin");
	contro(1, 0);
	while (1)
	{
		char phim;
		if (kbhit())
		{
			phim = getch();
			if (phim == 13)
				break;
			if (phim == 80)
			{
				if (vt < 4)
				{
					vt++;
					vtd = vt - 1;
					contro(vt, vtd);
				}
			}
			if (phim == 72)
			{
				if (vt > 1)
				{
					vt--;
					vtd = vt + 1;
					contro(vt, vtd);
				}
			}
		}
	}
	if (vt == 1)
	{
		system("cls");
		state = INFO;
		info();
	}
	if (vt == 2)
	{
		system("cls");
		printf("dung cac phim len xuong trai phai de diu khien ran\n");
		printf("moi lan an moi +5d\n");
		printf("khi dam vao than thi gameover\n");
		printf("enter de quay lai menu...");
		char enter;
		while (1)
		{
			enter = getch();
			if (enter == 13)
				break;
		}
		menu();
	}
	if (vt == 3)
	{
		sort_score(hs,turn);
		system("cls");
		printf("esc de thoat game...");
		char esc;
		while (1)
		{
			esc = getch();
			if (esc == 27)
				exit(1);
		}
		menu();
	}
	if (vt == 4)
	{
		system("cls");
		output(hs,5);
		printf("nguoi lam >>DANGCAP07<<\n");
		printf("enter de quay lai menu...");
		char enter;
		while (1)
		{
			enter = getch();
			if (enter == 13)
				break;
		}
		menu();
	}
	state = 100;
}
void gameover()
{
	system("cls");
	int a;
	printf("score: %d\n\n", score);
	printf("GAME OVER\n");
	FILE *fptr;
	fptr = fopen(filename, "a+");
	hs[turn].scoreg = score;
	sort_score(hs,turn);
	fprintf(fptr, "name: %s", hs[turn].nameg);
	fprintf(fptr, "\n");
	fprintf(fptr, "Score: %d", hs[turn].scoreg);
	fprintf(fptr, "\n");
	++turn;
	fclose(fptr);
	score = 0;
	char c;
	printf("esc quay lai menu...  ");
	while (1)
	{
		c = getch();
		if (c == 27)
		{
			system("cls");
			menu();
		}
	}
	state = 100;
}

void game()
{
	printf("Score: ");
	printf("\n");
	box();
	hamran();
	int key = 0;
	gotoxy(getX(ran[0]), getY(ran[0]));
	while (state == GAME)
	{ //vong lap vo han cho toi 1 dk nao do o man game
		if (kbhit())
		{ //ham kbhit() xuat nhap 1 phim tu ban phim tra ve gia tri 1/0
			key = getch();
			switch (key)
			{
			case 72:
				if (vx != 0)
				{
					vy = -1;
					vx = 0;
				}
				break;
			case 80:
				if (vx != 0)
				{
					vy = 1;
					vx = 0;
				}
				break;
			case 75:
				if (vy != 0)
				{
					vy = 0;
					vx = -1;
				}
				break;
			case 77:
				if (vy != 0)
				{
					vy = 0;
					vx = 1;
				}
				break;
			}
		}
		if (dk % 3000 == 0)
		{ //dieu kien de van toc ban dau tuy thuoc vao so dc chia
			gotoxy(getX(ran[dai - 1]), getY(ran[dai - 1]));
			printf(" ");
			int i = dai - 1;
			for (i; i > 0; i--)
			{
				ran[i] = ran[i - 1];
			}
			ran[0] += vy;
			ran[0] += vx * 100;
			if (getY(ran[0]) == 1)
				ran[0] += 25;
			if (getY(ran[0]) == 27)
				ran[0] -= 25;
			if (getX(ran[0]) == 0)
				ran[0] += 77 * 100;
			if (getX(ran[0]) == 78)
				ran[0] -= 77 * 100;
			gotoxy(getX(ran[0]), getY(ran[0]));
			printf("%c", 220);
			gotoxy(getX(moi), getY(moi));
			printf("%c", 232);
			if (ran[0] == moi)
			{
				gotoxy(getX(moi), getY(moi)); //dieu kien an moi
				printf("%c", 220);
				dai++;
				score += 5;
				randommoi();
				indiem();
			}
			for (i = 1; i < dai; i++)
			{
				if (ran[0] == ran[i])
				{ //dieu kien dam vao than la chet
					state = GAMEOVER;
					gameover();
				}
			}
		}
		dk++;
	}
	state = 100;
}


int main()
{
	
	Nocursortype();
	while (1)
	{
		switch (state)
		{
		case MENU:
			menu();
			break;
		case GAME:
			game();
			break;
		case GAMEOVER:
			gameover();
			break;
		}
	}
	return 0;
}
