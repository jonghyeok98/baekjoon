// boj s2 18111
// 마인크래프트

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<int>> v;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, B;
	cin >> N >> M >> B;

	v.resize(N, vector<int>(M));
	int time = INT_MAX, height = 0;

	for(int i=0; i<N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> v[i][j];
	}

	for(int h=0; h<=256; h++)
	{
		int push = 0;
		int pop = 0;
		for(int i=0; i<N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (v[i][j] - h > 0)
					pop += v[i][j] - h;
				else if (v[i][j] - h < 0)
					push += h - v[i][j];
			}
		}
		if(pop+B >= push)
		{
			int curTime = pop * 2 + push;
			if(time>=curTime)
			{
				time = curTime;
				height = h;
			}
		}
	}

	cout << time << " " << height;


	
	return 0;
}


