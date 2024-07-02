// boj 1697 s1 숨바꼭질

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static int N, K;
static vector<int>v;
void BFS(int node);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	if(N>K)
	{
		cout << N-K;
		return 0;
	}
	v.resize(100001, -1);

	BFS(N);
	cout << v[K];
	

	return 0;
}

void BFS(int node)
{
	queue<int> q;
	v[node] = 0;
	q.push(node);

	while(v[K]==-1)
	{
		int cur = q.front();
		q.pop();

		for(int next : {cur-1, cur+1, cur*2})
		{
			if (next < 0 || next > 100000) continue;
			if(v[next]==-1)
			{
				v[next] = v[cur] + 1;
				q.push(next);
			}
		}
	}
}
