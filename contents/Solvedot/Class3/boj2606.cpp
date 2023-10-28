// boj s3 2606
// 바이러스

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<int>> G;
static vector<bool> visited;

int BFS(int node);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int V, E;
	cin >> V >> E;

	G.resize(V+1);
	visited.resize(V + 1, false);

	for(int i=0; i<E; i++)
	{
		int start, end;
		cin >> start >> end;
		G[start].push_back(end);
		G[end].push_back(start);
	}

	int result = BFS(1);
	cout << result;
	
	return 0;
}


int BFS(int node)
{
	int count = 0;
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while(!q.empty())
	{
		int now = q.front();
		q.pop();

		for(int i : G[now])
		{
			if(!visited[i])
			{
				q.push(i);
				visited[i] = true;
				count++;
			}
		}

	}

	return count;
}
