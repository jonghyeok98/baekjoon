#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include"tetris.h"      // �� ������� 

void init();
void gotoxy(int x, int y);
void removeCursor();
void makewall(int(*map)[30]);
void printmap(int(*map)[30]);
void makerand();
void makeblock(int(*map)[30]);
void makenext(int(*map)[30]);
void playgame(int(*map)[30]);
int checkcrash(int(*map)[30], int n);
void removeblock(int(*map)[30]);
int checktime(int (*map)[30], int n);
void checkline(int (*map)[30]);


// ��Ʈ���� �����
clock_t start, end;



int main(void)
{
	removeCursor(0);
	srand((unsigned)time(NULL));
	makewall(map);
	makenext(map);
	
	while (t.gameover)
	{
		init();
		makerand();
		makeblock(map);
		printmap(map);
		playgame(map);
	
		

	}
}

void init()                    
{
	// �� ������ǥ, ��� �ʱ�ȭ
	t.curX = 15, t.curY = 12;
	t.rotation = 0;
}

void gotoxy(int x, int y)                  
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void removeCursor(char show)                   
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void makewall(int(*map)[30])             
{
	// ���̶� ��� ��輱 �����
	for (int i = 0; i < 60; i++)
	{
		map[i][0] = -1;
		map[i][29] = -1;
	}
	for (int i = 0; i < 30; i++)
	{
		map[0][i] = -1;
		map[59][i] = -1;
	}
	for (int i = 1; i < 29; i++)
	{
		map[10][i] = 2;
	}
}

void makenext(int(*map)[30])                
{
	// ���� next �����
	for (int i = 0; i <= 4; i++)
	{
		map[i + 2][2] = 1;
		map[i + 2][6] = 1;
		map[i + 2][8] = 1;
		map[i + 2][20] = 1;
		map[i + 2][i + 13] = 1;
		map[6 - i][i + 13] = 1;

	}
	for (int i = 0; i <= 2; i++)
	{
		map[2][i + 9] = 1;
		map[4][i + 9] = 1;
		map[6][i + 9] = 1;
	}
	for (int i = 3; i <= 5; i++)
	{
		map[i][i] = 1;
	}
	map[2][19] = 1;
	map[2][21] = 1;

}

void printmap(int(*map)[30])                   
{
	// (0, 0) ��ǥ�� �̵� �� �� ���
	gotoxy(0, 0);
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			switch (map[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("��");
				break;
			case -1:
				printf("��");
				break;
			case 2:
				printf("==");
				break;

			}
		}
		printf("\n");
	}
}

void makerand()                  
{
	// �� �������� ����
	t.curblock = t.nextblock;
	t.nextblock = rand() % 7;
}

void makeblock(int(*map)[30])
{
	// ���� ���� ���� �� ������ ������ ����ִٸ� �� ����
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			map[i + t.absY][j + t.absX] = blocks[t.nextblock][0][i][j];
			if (map[i + t.curY][j + t.curX] == 0)
				map[i + t.curY][j + t.curX] = blocks[t.curblock][t.rotation][i][j];
		}
	}
}

void removeblock(int(*map)[30])
{
	//���� ��ǥ�� �������� ������� ���� ���°��� ����
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (map[i + t.curY][j + t.curX] != -1)
				map[i + t.curY][j + t.curX] = 0;
		}
	}
}

int checktime(int (*map)[30], int n)
{
	//���� �ٷ� �Ʒ� ������ ��������� t.speed ��ŭ�� �ð��� �������� ��ĭ �Ʒ��� �̵���
	//���� �ٷ� �Ʒ��� ���� �ִٸ� t.speed ��ŭ�� �ð��� �������� ���� ������Ŵ
	end = clock();
	if (difftime(end,start)>n)
	{
		start = end;
		if (checkcrash(map, 3))
		{
			removeblock(map);
			t.curY++;
			makeblock(map);
			printmap(map);
			return 0;
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (map[i + t.curY][j + t.curX] == 1)
						map[i + t.curY][j + t.curX] = -1;
				}
			}
			return 1;
		}
	}
	return 0;
}

void playgame(int(*map)[30])
{
	int k = 1;
	while (k)
	{
		if (checktime(map, t.speed))
			k = 0;
		if (_kbhit())
		{
			int key = _getch();
			switch (key)
			{
			case LEFT:
				if (checkcrash(map, 1))
				{
					removeblock(map);
					t.curX--;
					makeblock(map);
					printmap(map);
				}
				break;
			case RIGHT:
				if (checkcrash(map, 2))
				{
					removeblock(map);
					t.curX++;
					makeblock(map);
					printmap(map);
				}
				break;
			case UP:
				if (checkcrash(map, 0))
				{
					removeblock(map);
					makeblock(map);
					printmap(map);
				}
				else if (t.rotation == 0)
					t.rotation = 3;
				else
					t.rotation--;
				break;
			case DOWN:
				if (checkcrash(map, 3))
				{
					removeblock(map);
					t.curY++;
					makeblock(map);
					printmap(map);
				}

				break;
			}
			if (key == SPACEBAR)
			{
				while (checkcrash(map, 3))
				{
					removeblock(map);
					t.curY++;
				}
				makeblock(map);
				printmap(map);
			}
		}
		if (checkcrash(map, 4) == 0)
		{
			k = 0;
			t.gameover = 0;
		}
		checkline(map);
	}
}

int checkcrash(int(*map)[30], int n)
{
	// �浹�� üũ�ϴ� �Լ�
	int check = 0;
	switch (n)
	{
	case 0:                        // �� ȸ�� �浹 üũ
		t.rotation=(t.rotation+1)%4;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (map[t.curY + i][t.curX + j] ==-1 && blocks[t.curblock][t.rotation][i][j] == 1)
					return 0;
			}
		}
		break;
	case 1:                        // ���� �̵� �浹 üũ
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (map[t.curY + i][t.curX + j - 1] == -1)
					check = 1;
				else
					check = 0;
				if (check == 1 && blocks[t.curblock][t.rotation][i][j] == 1)
					return 0;
			}
		}
		break;
	case 2:                        // ������ �̵� �浹 üũ
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (map[t.curY + i][t.curX + j + 1] == -1)
					check = 1;
				else
					check = 0;
				if (check == 1 && blocks[t.curblock][t.rotation][i][j] == 1)
					return 0;
			}
		}
		break;
	case 3:                        // �Ʒ� �̵� �浹 üũ
		for (int i = 0; i < 4; i++) 
		{
			for (int j = 0; j < 4; j++)
			{
				if (map[t.curY + i + 1][t.curX + j] == -1)
					check = 1;
				else
					check = 0;
				if (check == 1 && blocks[t.curblock][t.rotation][i][j] == 1)
					return 0;
			}
		}
		break;
	case 4:                       // ��� ��輱 �浹 üũ
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (map[i + 12][j + 15] == -1)
					return 0;
			}
		}
		break;
	}
	return 1;


}

void checkline(int(*map)[30])
{
	// �� ���� ������ ��� ���� ����� �ش� �� �����ִ� ��� ���� ���� 
	int cnt = 0;
	for (int i = t.curY; i < 59; i++)
	{
		for (int j = 1; j < 29; j++)
		{
			if (map[i][j] == -1)
				cnt++;
		}
		if (cnt == 28)
		{
			for (int k = 1; k < 29; k++)
			{
				map[i][k] = 0;
			}
			for (int k=i ; k >12 ; k--)
			{
				for (int m = 1; m < 28; m++)
				{
					map[k][m] = map[k-1][m];
				}
			}
			printmap(map);
		}
		else
			cnt = 0;
	}
}