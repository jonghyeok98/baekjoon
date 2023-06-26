// boj 15829 Hashing
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int main(int argc, char* argv[])
{
	//ios_base::sync_with_stdio(false);

	string input;
	int N;
	long long r = 1;
	long long HashResult = 0, M=1234567891;
	cin >> N >> input;

	for(int i=0; i<N; i++)
	{
        // 수가 계속 커지는 것을 방지하기 위해 M으로 계속 mod 해줌
		HashResult = (HashResult + (input[i] - 96) *r)%M;
		r = (r * 31) % M;
	}
	printf("%lld\n", HashResult);
	return 0;
}