// boj s3 11727
// 2xn 타일링 2
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int dp[1001] = {0};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	dp[4] = 11;
	dp[5] = 19;

	for (int i = 4; i < 1001; i++)
		dp[i] = ((dp[i - 2]*2) + dp[i - 1])%10007;

	cout << dp[N];

	
	return 0;
}




