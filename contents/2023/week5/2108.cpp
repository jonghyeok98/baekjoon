// boj s3 2108
// 통계학

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int countMode[8001]={0};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> v;
	cin >> N;

	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		if (v[i] >= 0)
			countMode[v[i]]++;
		else
			countMode[abs(v[i]) + 4000]++;
	}

	sort(v.begin(), v.end());

	int avg = 0, mid = 0, mode=0, range = 0;

	// 평균
	for (int i : v)
		avg += i;

	avg = round(1.0*avg/N); 

	// 중앙값
	mid = v[(N / 2)];

	// 최빈값
	int max = 0;
	for(int i=0; i<8001; i++)
	{
		if (countMode[i] > max)
			max = countMode[i];
	}

	vector<int> modes;
	for(int i=0; i<8001; i++)
	{
		if(max==countMode[i])
		{
			if(i<=4000) 
			{
				modes.push_back(i);
			}
			else
			{
				modes.push_back((i - 4000) * (-1));
			}
		}
	}

	if (modes.size() > 1)
	{
		sort(modes.begin(), modes.end());
		mode = modes[1];
	}
	else
		mode = modes[0];
	
	// 범위
	range = v[N - 1] - v[0];
	
	cout << avg << '\n' << mid << '\n' << mode << '\n' << range;


	return 0;
}


