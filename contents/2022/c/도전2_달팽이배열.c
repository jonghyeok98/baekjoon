#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX_LEN 100



int main(void)
{
	int n, k;   // ���� ����
	int len;  \
	int b = 0; 
	int count = 1; // n*n �Ǹ� ����
	printf("���ڸ� �Է��Ͻÿ�: ");
	scanf("%d", &n);
	
	k = n;
	int arr[MAX_LEN][MAX_LEN] = { 0 };  // �迭 �ʱ�ȭ
	while(count<=n*n)
	{
		len = k - 1;  // ä������ ���� ����(n-1ȸ)
		if (k == 1)
		{
			arr[b][b] = count;
			break;
		}
		else if(k == 0)
		{
			break;
		}
		else
		{
			for (int j = 0; j < len; j++)
			{
				arr[0 + b][j + b] = count;
				count++;
			}
			for (int i = 0; i < len; i++)
			{
				arr[i + b][len + b] = count;
				count++;
			}
			for (int j = len; j >= k - len; j--)
			{
				arr[len + b][j + b] = count;
				count++;
			}
			for (int i = len; i >= k - len; i--)
			{
				arr[i + b][0 + b] = count;
				count++;
			}
		}
		
		k -= 2; // ���� ���� ���
		b++;
		
	}

	for (int i = 0; i < n; i++)  // �迭 ���
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	


	return 0;
}

