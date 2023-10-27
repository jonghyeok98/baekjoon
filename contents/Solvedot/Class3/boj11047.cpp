// boj s4 11047
// 동전 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<climits>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int K, N;
	cin >> N >> K;
	
	vector<int> v;
	v.resize(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	int count = 0;
	int sum = K;
	while(sum>0)
	{
		int q = INT_MAX;
		int value = 0;
		for(int i : v)
		{
			if(sum/i > 0 && q >= sum/i)
			{
				q = sum / i;
				value = i;
			}
		}
		count += q;
		sum -= q * value;
	}

	cout << count;

	
	return 0;
}


