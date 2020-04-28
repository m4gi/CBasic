#include <stdio.h>
#include <String.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
	char kindOfTime[2];
	int hour, minute, wordCount;
	char stringWord[20];
} Textmsg;
void inputFile(FILE *fb, Textmsg textmsg[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		fscanf(fb, "%d", &textmsg[i].hour);
		fscanf(fb, ":%d", &textmsg[i].minute);
		fscanf(fb, "%d", &textmsg[i].wordCount);
		fscanf(fb, "%s", textmsg[i].kindOfTime);
		fscanf(fb, "\n%[^\n]", textmsg[i].stringWord);
	}
}
void toLower(char arr[])
{
	int i;
	for (i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z')
		{
			arr[i] += 32;
		}
	}
}
int forbidden(char word[], char forb[][30], int n)
{
	int i;
	char arr[30];
	strcpy(arr, word);
	toLower(arr);
	for (i = 0; i < n; i++)
	{
		if (strstr(arr, forb[i]) != NULL)
		{
			return 1;
		}
	}
	return 0;
}

int iLoveYou(char word[])
{
	int n, i, j, k, I, J;
	char arr[30], arr1[20];
	strcpy(arr1, "i love you");
	n = strlen(arr1);
	strcpy(arr, word);
	toLower(arr);

	for (i = 0; arr1[i] != '\0'; i++)
	{
		for (j = 0; word[j] != '\0'; j++)
		{
			if (arr1[i] == arr[j])
			{
				I = i, J = j;
				for (k = 0; k < n; k++)
				{
					if (arr1[I++] != arr[J++])
					{
						break;
					}
					if (k == n - 1)
					{
						return 1;
					}
				}
			}
		}
	}
}
int word(char word[], char dic[][30], int n, int countWord)
{
	int i, j, t, k, mark = 0;
	;
	char arr[30];
	char temp[20];
	strcpy(arr, word);
	toLower(arr);
	for (i = 0, j = 0; i < countWord; i++)
	{
		k = 0;
		for (j = 0; arr[j] != ' '; j++)
		{
			temp[k++] = arr[j];
			if (arr[j] == '\0')
			{
				break;
			}
		}
		j++;
		for (t = 0; t < n; t++)
		{
			if (strcmp(temp, dic[t]) == 0)
			{
				mark++;
				break;
			}
		}
		memset(temp, '\0', sizeof(temp));
	}
	if (countWord - mark >= 3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main(int argc, char const *argv[])
{
	char forb[10][30], dic[10][30];
	int i, j, nForb, nDic, nText, check = 1;
	FILE *fb;
	fb = fopen("textmsg.txt", "r");
	Textmsg textmsg[10];
	fscanf(fb, "%d", &nDic);
	for (i = 0; i < nDic; i++)
	{
		fscanf(fb, "%s", dic[i]);
	}
	fscanf(fb, "%d", &nForb);
	for (i = 0; i < nForb; i++)
	{
		fscanf(fb, "%s", forb[i]);
	}
	fscanf(fb, "%d", &nText);
	inputFile(fb, textmsg, nText);
	for (j = 0; j < nText; j++)
	{
		for (i = 0; i < 50; i++)
		{
			if (textmsg[j].stringWord[i] == '\n')
			{
				textmsg[j].stringWord[i] = '\0';
				break;
			}
		}
	}
	for (i = 0; i < nText; i++)
	{
		if (strcmp(textmsg[i].kindOfTime, "AM") == 0 && textmsg[i].hour >= 1 && textmsg[i].hour < 7)
		{
			if (iLoveYou(textmsg[i].stringWord) == 1)
			{
				check = 0;
			}
			else if (word(textmsg[i].stringWord, dic, nDic, textmsg[i].wordCount) == 1)
			{
				check = 0;
			}
			else if (forbidden(textmsg[i].stringWord, forb, nForb) == 1)
			{
				check = 0;
			}
			if (check == 0)
			{
				printf("Message #%d: FAILED TO SEND\n", i + 1);
			}
			else
			{
				printf("Message #%d: %s\n", i + 1, textmsg[i].stringWord);
			}
		}
		else
		{
			printf("Message #%d: %s\n", i + 1, textmsg[i].stringWord);
		}
	}
	getch();
	return 0;
}
