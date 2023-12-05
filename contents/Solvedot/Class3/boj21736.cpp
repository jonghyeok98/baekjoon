// boj s2 21736
// 헌내기는 친구가 필요해
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

static vector<string> G;
static vector<vector<bool>> visited;
static int dx[]={0, 0, -1, 1};
static int dy[]={-1, 1, 0, 0};
static int result=0;
static int N, M;

void BFS(pair<int, int> start);

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> N >> M;

    pair<int, int> startPos;
    G.resize(N);
    visited.resize(N, vector<bool>(M, false));

    for(int i=0; i<N; i++)
    {
        cin >> G[i];
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(G[i][j]=='I')
                startPos = make_pair(i, j);
        }
    }

    BFS(startPos);
    if(result == 0)
        cout << "TT";
    else
        cout << result;

    return 0;
}

void BFS(pair<int, int> start)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        
        if(G[now.first][now.second]=='P')
            result++;

        for(int i=0; i<4; i++)
        {
            int nextX = now.second+dx[i];
            int nextY = now.first+dy[i];
            if(nextY >= 0 && nextY < N && nextX >= 0 && nextX < M)
            {
                if(!visited[nextY][nextX] && G[nextY][nextX]!='X')
                {
                    visited[nextY][nextX]=true;
                    q.push(make_pair(nextY, nextX));
                }    
            }
            
        }

    }

}