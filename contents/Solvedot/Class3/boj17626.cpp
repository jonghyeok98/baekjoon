// boj s3 17626
// Four Squares
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int dp[50001] = {0};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i*i <= N; i++)
		dp[i*i] = 1;
 
	for(int i=1; i<=N; i++)
	{
		if(dp[i]!=0)
			continue;
		for(int j=1; j*j<=i; j++)
		{
			if (dp[i] == 0)
				dp[i] = dp[j * j] + dp[i - j * j];
			else
				dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
		}
	}

	cout << dp[N];

	
	return 0;
}




