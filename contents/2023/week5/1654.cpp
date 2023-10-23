// boj s2 1654
// 랜선 자르기

// 이분 탐색으로 시간 복잡도를 줄여야 시간 초과를 피할 수 있다
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int K, N;
	cin >> K >> N;

	vector<long long> v;
	v.resize(K);

	long long _max = 0;

	for (int i = 0; i < K; i++)
	{
		cin >> v[i];
		_max = max(_max, v[i]);
	}

	
	long long result = 0;
	long long left = 1, right = _max;

	while(left<=right)
	{
		long long mid = (left + right) / 2;
		long long count = 0;

		for(int i=0; i<K; i++)
		{
			count += v[i] / mid;
		}

		if(count >= N)
		{
			left = mid + 1;
			result = max(result, mid);
		}
		else
		{
			right = mid - 1;
		}
	}


	cout << result;

	
	return 0;
}


