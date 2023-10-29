// boj s3 9095
// 1, 2, 3 더하기

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int dp[12] = {0};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for(int i=4; i<12; i++)
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

	for(int i=0; i<N; i++)
	{
		int temp;
		cin >> temp;
		cout << dp[temp] << '\n';
	}
	
	
	return 0;
}




