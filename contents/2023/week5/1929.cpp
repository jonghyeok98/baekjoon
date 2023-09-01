// boj s3 1929 소수구하기

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime[1000001] = {false};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> M >> N;

	isPrime[0] = true;
	isPrime[1] = true;

	for(int i=2; i<=sqrt(N); i++)
	{
		for(int j=2; i*j<=N; j++)
		{
			isPrime[i * j] = true;
		}
	}


	for(int i=M; i<=N; i++)
	{
		if (!isPrime[i])
			cout << i << '\n';
	}

	return 0;
}

