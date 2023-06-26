// boj 1978 소수 찾기
// 에라토스테네스의 체 구현
#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	vector<bool> isPrime(1001, true);
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i*i<=1000; i++)
	{
		if(isPrime[i])
		{
			for (int j = i * i; j <= 1000; j+=i)
				isPrime[j] = false;
		}
	}
	int N, count = 0;
	cin >> N;

	for(int i=0; i<N; i++)
	{
		int num;
		cin >> num;
		if (isPrime[num])
			count++;
	}
	cout << count;

	return 0;
}