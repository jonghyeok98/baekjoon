// boj 2609 최대공약수와 최소공배수

#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int find_gcd(int a, int b);

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int a, b, gcd;
	cin >> a >> b;
	gcd = find_gcd(a, b);
	cout << gcd << '\n' << (a*b)/gcd;
	
	
	return 0;
}

// 유클리드 호제법
// 24와 18의 최대공약수와 최소공배수
// 최소공배수 = 두 수의 곱 / 최대공약수
// 24 = 18*1 + 6
// 18 = 6*3 + 0   -> 0이 되면 최대공약수를 구함
int find_gcd(int a, int b)
{
	int gcd;
	while (true)
	{
		gcd = a % b;
		a = b;
		b = gcd;
		if (gcd == 0)
			return a;
	}
	
}