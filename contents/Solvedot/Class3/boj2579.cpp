// boj s3 2579
// 계단 오르기

#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> dp(N, -1);
	vector<int> step;
	step.resize(N);

	for (int i = 0; i < N; i++)
		cin >> step[i];

	dp[0] = step[0];
	dp[1] = step[0]+step[1];
	dp[2] = max(step[0] + step[2], step[1] + step[2]);

	for(int i=3; i<N; i++)
	{
		dp[i] = max(dp[i - 2] + step[i], dp[i - 3] + step[i-1]+step[i]);
	}

	cout << dp[N-1];
	
	return 0;
}


