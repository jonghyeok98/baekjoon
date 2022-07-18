#include<stdio.h>




int main(void)
{
	int a, b,n;
	

	scanf("%d", &n);
	for (int j = 1; j <= n; j++)
	{
		scanf("%d %d", &a, &b);
		int result = 1;
		for (int i = 2; i <= 99; i++)
		{
			if (a % i == 0 && b % i == 0)
			{
				result *= i;
				a /= i;
				b /= i;
			}
		}
		result *= a * b;
		printf("%d\n", result);
	}
	
}

