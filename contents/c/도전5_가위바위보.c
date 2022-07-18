#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int main(void)
{
	int user, computer = 0;
	srand(time(NULL));
	computer = rand() % 3 + 1;
	printf("바위는 1 가위는 2 보자기는 3\n");
	scanf("%d", &user);
	
	switch (user)
	{
	case 1:
		if (computer == 1)
		{
			printf("당신은 바위선택, 컴퓨터는 바위선택, 비겼습니다!\n");
			break;
		}
		if (computer == 2)
		{
			printf("당신은 바위선택, 컴퓨터는 가위선택, 이겼습니다!\n");
			break;
		}
		if (computer == 3)
		{
			printf("당신은 바위선택, 컴퓨터는 보자기선택, 졌습니다!\n");
			break;
		}
		
	case 2:
		if (computer == 1)
		{
			printf("당신은 가위선택, 컴퓨터는 바위선택, 졌습니다!\n");
			break;
		}
		if (computer == 2)
		{
			printf("당신은 가위선택, 컴퓨터는 가위선택, 비겼습니다!\n");
			break;
		}
		if (computer == 3)
		{
			printf("당신은 가위선택, 컴퓨터는 보자기선택, 이겼습니다!\n");
			break;
		}
	case 3:
		if (computer == 1)
		{
			printf("당신은 보자기선택, 컴퓨터는 바위선택, 이겼습니다!\n");
			break;
		}
		if (computer == 2)
		{
			printf("당신은 보자기선택, 컴퓨터는 가위선택, 졌습니다!\n");
			break;
		}
		if (computer == 3)
		{
			printf("당신은 보자기선택, 컴퓨터는 보자기선택, 비겼습니다!\n");
			break;
		}
	}


	return 0;
}

