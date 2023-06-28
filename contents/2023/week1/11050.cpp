// boj 11050 이항계수 1

#include<iostream>

using namespace std;

void find_num(int a, int b);
int sum = 0;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	find_num(a, b);

	cout << sum;
   
	return 0;
}

void find_num(int a, int b)
{
	if ((a==0 || b == 0) || a==b)
	{
		sum++;
		return;
	}

	find_num(a - 1, b - 1);
	find_num(a - 1, b);
}
