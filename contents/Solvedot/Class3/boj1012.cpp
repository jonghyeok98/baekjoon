// boj s2 1012
// 유기농 배추
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

static vector<vector<bool>> G;
static vector<vector<bool>> visited;

static int dx[]={0, 0, -1, 1};
static int dy[]={-1, 1, 0, 0};

static int N, M;

void BFS(int x, int y);

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int T;
    cin >> T;

    for(int i=0; i<T; i++)
    {
        int K;
        cin >> M >> N >> K;
        int count=0;

        // M, N이 같은 수가 들어왔을 경우 resize가 작동하지 않으므로 초기화 해주어야한다
        G=vector<vector<bool>>(N, vector<bool>(M, false));
        visited=vector<vector<bool>>(N, vector<bool>(M, false));
        for(int j=0; j<K; j++)
        {
            int x, y;
            cin >> x >> y;
            G[y][x]=true;
        }

        for(int j=0; j<N; j++)
        {
            for(int k=0; k<M; k++)
            {
                if(G[j][k] && !visited[j][k])
                {
                    BFS(j, k);
                    count++;
                }
            }
        }
        cout << count << '\n';
    }

    return 0;
}

void BFS(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x]=true;

    while(!q.empty())
    {
        int curY=q.front().first;
        int curX=q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nextX=curX+dx[i];
            int nextY=curY+dy[i];
            if(nextX >= 0 && nextY >= 0 && nextX<M && nextY < N && G[nextY][nextX] && !visited[nextY][nextX])
            {
                visited[nextY][nextX]=true;
                q.push({nextY, nextX});
            }
        }
    }

    
}