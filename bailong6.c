
#include <stdio.h>
#include <stdlib.h>
#include <conio.h >
#include <string.h>
#include <time.h>
char store[10] = {};
int falses = 0;
int exist(char *linkfile)
{
	int existed = 0;
	FILE *f = fopen(linkfile, "r");
	if (f != NULL)
	{
		existed = 1;
	}
	fclose(f);
	return existed;
}

void random(char *linkfile, char *a)
{
	fflush(stdin);
	char c;
	//random number
	srand(time(NULL));
	int number = 1 + rand() % 19;
	//seach the word in the line number time
	int count = 0;
	fflush(stdin);
	FILE *f = fopen(linkfile, "r");
	do
	{
		fscanf(f, "%[^\n]", a);
		count++;
	} while (((c = fgetc(f)) != EOF) && (count != number));
	fclose(f);
}

int ask()
{
	char c[5];
	fflush(stdin);
	printf("Would you like play hangman (yes/no)?\n");
	scanf("%s", c);
	strlwr(c);
	if (strcmp(c, "yes") == 0)
	{
		return 1;
	}
	else if (strcmp(c, "no") == 0)
		;
	{
		printf("Thanks for playing\n");
		return 0;
	}
}

char upr(char *c)
{
	strupr(c);
	return *c;
}
void display(char word[10])
{
	int slots = strlen(word);
	int i;
	char guess;
	printf("Your currently %d incorrect guesses\n", falses);
	printf("Here is your puzzle\n");
	for (i = 0; i < slots; i++)
	{
		if (store[i] == 0)
		{
			printf("_ ");
		}
		else
		{
			printf("%c", store[i]);
		}
	}
	printf("\n");
	printf("Please enter your guess. \n");
	guess = getch();
	printf("%c\n", upr(&guess));
	printf("\n");
	////check guess true or false
	int state = 0;
	//th1:guess true and have not in store

	for (i = 0; i < slots; i++)
	{
		if ((guess == word[i]) && (guess != store[i]))
		{
			store[i] = word[i];
			state = 1;
		}
	}
	if (state == 1 && (strcmp(word, store) != 0))
	{
		printf("Congratulation! You guess the letter in the puzzle.\n");
	}
	// th2:guess false or same pravte guess
	if (state == 0)
	{
		int count = 0;
		for (i = 0; i < slots; i++)
		{
			if ((guess != word[i]))
			{
				count++;
			}
		}
		//guess false
		if (count == slots)
		{
			printf("Sorry! That letter NOT in the puzzle.\n");
			falses++;
		}
		else
		//guess had in store
		{
			printf("Sorry! your have guessed the letter already.\n");
			printf("Now as count it a miss\n");
			falses++;
		}
		printf("\n");
	}
}
int input(char *linkfile)
{
	char q[10];
	printf("What file stores the puzzle words!\n");
	scanf("%[^\n]", q);
	strcat(linkfile, "D:\\AT\\Code\\C\\");
	strcat(linkfile, q);
	if (exist(linkfile) != 0)
	{
		printf("\n");
		int state = ask();
		return state;
	}
	else
	{
		printf("file is not loaded\n");
	}
	return 0;
}

void handin(char word[50])
{
	int i;
	if (falses == 5)
	{
		printf("Sorry! You made incorrect 5 guess. You lose.\n");
		printf("the correct word was %s\n", word);
	}
	if (strcmp(word, store) == 0)
	{
		printf("Congratuation!You got the correct word,%s\n", word);
	}
	for (i = 0; i < 10; i++)
	{
		store[i] = 0;
	}
	falses = 0;
}
int main()
{
	char target[50] = {};
	int question;
	int state = input(target);
	do
	{
		fflush(stdin);
		char word[10] = {};
		if (state == 1)
		{
			random(target, word);
			while (strcmp(word, store) != 0 && falses != 5)
			{
				display(word);
			}
			handin(word);
			question = ask();
		}
	} while (question != 0);
	return 0;
}
