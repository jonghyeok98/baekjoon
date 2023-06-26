#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int stringlen();
char* dynamicmem(int n);
void insertstr(char* str1, int n);
void clearinsertbuffer();
void reversestr(char str1[]);


int main(void)
{
	int n; // ���ڿ� �ִ����
	
	n=stringlen();                 // ���ڿ� ���� �Է�
	char* str1 = dynamicmem(n);         // �޸� �����Ҵ�
	clearinsertbuffer();
	insertstr(str1, n);        // ���ڿ� �Է�
	reversestr(str1);
	
	
	
	
	free(str1);
	return 0;
}



int stringlen()         // ���ڿ� �ִ���� �Է�
{
	int n; 
	printf("���ڿ� �ִ� ���� �Է�: ");
	scanf("%d", &n);   
	return n;
}

char* dynamicmem(int n)   // ���ڿ� ���� �Ҵ�
{
	char* str = (char*)malloc(sizeof(char) * n);   // char�� ũ�� n �迭 �Ҵ�
	return str;           
}

void insertstr(char* str1, int n)    // ���ڿ� �Է�
{
	printf("���ڿ� �Է�: ");
	fgets(str1, sizeof(char) * n, stdin);
	str1[strlen(str1) - 1] = 0;
}

void clearinsertbuffer()      // �Է� ���� ����
{
	while (getchar() != '\n');	
}

void reversestr(char str1[])
{
	for (int i = strlen(str1)-1; i > 0; i--)
	{
		if (str1[i] == ' ')
		{
			printf("%s ", &str1[i+1]);
			str1[i] = 0;
		}
		
	}
	printf("%s", &str1[0]);
}


