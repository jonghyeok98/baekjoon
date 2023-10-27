// boj s3 1463
// 1로 만들기

#include <iostream>
#include <vector>

using namespace std;

static vector<int> dp(1000001, -1);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for(int i=4; i<1000001; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if(i%3==0)
		{
			if(dp[i]>dp[i/3]+1)
				dp[i] = dp[i / 3] + 1;
		}
		if(i%2==0)
		{
			if (dp[i] > dp[i / 2] + 1)
				dp[i] = dp[i / 2] + 1;
		}
	}

	int N;
	cin >> N;
	cout << dp[N];

	
	return 0;
}


