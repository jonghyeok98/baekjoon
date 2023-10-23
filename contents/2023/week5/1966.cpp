// boj s3 1966
// 프린터 큐
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M;
	cin >> T;

	for(int i=0; i<T; i++)
	{
		queue<pair<int, int>> q;
		vector<int> weight;
		cin >> N >> M;
		int count = 1;

		for(int j=0; j<N; j++)
		{
			int tmp;
			cin >> tmp;
			q.push({ tmp, j });
			weight.push_back(tmp);
		}

		sort(weight.begin(), weight.end());

		while(!q.empty())
		{
			pair<int, int> temp = q.front();
			if(temp.first==weight.back())
			{
				if (temp.second == M)
					break;
				weight.pop_back();
				q.pop();
				count++;
			}
			else
			{
				q.pop();
				q.push(temp);
			}
		}
		cout << count << '\n';
	}


	return 0;
}


