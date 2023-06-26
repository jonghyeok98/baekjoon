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
	int n; // 문자열 최대길이
	
	n=stringlen();                 // 문자열 길이 입력
	char* str1 = dynamicmem(n);         // 메모리 동적할당
	clearinsertbuffer();
	insertstr(str1, n);        // 문자열 입력
	reversestr(str1);
	
	
	
	
	free(str1);
	return 0;
}



int stringlen()         // 문자열 최대길이 입력
{
	int n; 
	printf("문자열 최대 길이 입력: ");
	scanf("%d", &n);   
	return n;
}

char* dynamicmem(int n)   // 문자열 동적 할당
{
	char* str = (char*)malloc(sizeof(char) * n);   // char형 크기 n 배열 할당
	return str;           
}

void insertstr(char* str1, int n)    // 문자열 입력
{
	printf("문자열 입력: ");
	fgets(str1, sizeof(char) * n, stdin);
	str1[strlen(str1) - 1] = 0;
}

void clearinsertbuffer()      // 입력 버퍼 비우기
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


