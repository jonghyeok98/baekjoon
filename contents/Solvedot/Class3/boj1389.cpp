// boj s1 1389
// 케빈 베이컨의 6단계 법칙
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;

static vector<vector<int>> G;
static vector<int> dist;
static int Min = INT_MAX;
static int N, M;

int BFS(int start);

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> N >> M;

    G.resize(N+1);
    dist.resize(N+1, -1);
    for(int i=1; i<=M; i++)
    {
        int start, end;
        cin >> start >> end;
        G[start].push_back(end);
        G[end].push_back(start);
    }
   
    int result;
    for(int i=1; i<=N; i++)
    {
        int kevin = BFS(i);
        if(Min > kevin)
        {
            Min = kevin;
            result = i;
        }
    }

    cout << result;

    return 0;
}

int BFS(int start)
{
    fill(dist.begin(), dist.end(), -1);
    
    queue<int> q;
    q.push(start);
    dist[start]=0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int next : G[node])
        {
            if(dist[next]==-1)
            {
                dist[next]=dist[node]+1;
                q.push(next);
            }
        }
    }

    int sum=0;
    for(int i=1; i<=N; i++)
        sum+=dist[i];

    return sum;
}