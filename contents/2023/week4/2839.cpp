// boj s4 2839 설탕배달
#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, ans=0;
	cin >> N;

	while(N>=0)
	{
		if(N%5==0)
		{
			ans += (N / 5);
			cout << ans;
			return 0;
		}
		N -= 3;
		ans++;
	}
	cout << -1;
	return 0;
}

