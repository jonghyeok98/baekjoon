#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int main(void)
{
	int user, computer = 0;
	srand(time(NULL));
	computer = rand() % 3 + 1;
	printf("������ 1 ������ 2 ���ڱ�� 3\n");
	scanf("%d", &user);
	
	switch (user)
	{
	case 1:
		if (computer == 1)
		{
			printf("����� ��������, ��ǻ�ʹ� ��������, �����ϴ�!\n");
			break;
		}
		if (computer == 2)
		{
			printf("����� ��������, ��ǻ�ʹ� ��������, �̰���ϴ�!\n");
			break;
		}
		if (computer == 3)
		{
			printf("����� ��������, ��ǻ�ʹ� ���ڱ⼱��, �����ϴ�!\n");
			break;
		}
		
	case 2:
		if (computer == 1)
		{
			printf("����� ��������, ��ǻ�ʹ� ��������, �����ϴ�!\n");
			break;
		}
		if (computer == 2)
		{
			printf("����� ��������, ��ǻ�ʹ� ��������, �����ϴ�!\n");
			break;
		}
		if (computer == 3)
		{
			printf("����� ��������, ��ǻ�ʹ� ���ڱ⼱��, �̰���ϴ�!\n");
			break;
		}
	case 3:
		if (computer == 1)
		{
			printf("����� ���ڱ⼱��, ��ǻ�ʹ� ��������, �̰���ϴ�!\n");
			break;
		}
		if (computer == 2)
		{
			printf("����� ���ڱ⼱��, ��ǻ�ʹ� ��������, �����ϴ�!\n");
			break;
		}
		if (computer == 3)
		{
			printf("����� ���ڱ⼱��, ��ǻ�ʹ� ���ڱ⼱��, �����ϴ�!\n");
			break;
		}
	}


	return 0;
}

