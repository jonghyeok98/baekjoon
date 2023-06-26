#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int strike();
int ball();

int main(void)
{
	int a,s,b;
	int computer[4] = { 0 };
	int user[4] = { 0 };
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		computer[i] = rand() % 10;
	}
	
	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			scanf("%d", &a);
			user[i] = a;
		}
		s = strike(computer, user);
		b = ball(computer, user);
		printf("%dstrike, %dball\n", s, b);
		if (s == 4)
		{
			printf("%dstrike, game over\n", s);
			break;
		}
	}
	

	return 0;
}

int strike(int computer[], int user[])
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (computer[i] == user[i])
			count++;
	}
	return count;
}

int ball(int computer[], int user[])
{
	int count = 0;
	int testball[4];
	for (int i = 0; i < 4; i++)
	{
		testball[i] = computer[i];
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
				continue;
			if (testball[j] == user[i])
			{
				testball[j] = 10;
				count++;
			}
		}
	}
	return count;
}


