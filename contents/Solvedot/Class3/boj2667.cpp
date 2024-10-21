// boj s1 2667
// 단지번호붙이기
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

using int32 = long;
using int64 = long long;

static int dx[] = {0, 0, -1, 1};
static int dy[] = {-1, 1, 0, 0};

static vector<vector<int>> G;
static vector<vector<bool>> visited;
static vector<int> result;

static int N;

int BFS(int y, int x);
 
int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> N;
    G.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));

    for(int i=0; i<N; i++)
    {
        string input;
        cin >> input;
        for(int j=0; j<N; j++)
        {
            G[i][j]=input[j]-'0';
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(G[i][j] && !visited[i][j])
            {
                int count = BFS(i, j);
                result.push_back(count);
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';

    for(int i : result)
        cout << i << '\n';
    
    return 0;
}

int BFS(int y, int x)
{
    queue<pair<int, int>> q;
    visited[y][x]=true;
    q.push({y, x});

    int count=1;

    while(!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        int nowY = node.first;
        int nowX = node.second;

        for(int i=0; i<4; i++)
        {
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];

            if(nextX>=0 && nextX<N && nextY >=0 && nextY<N)
            {
                if(G[nextY][nextX] && !visited[nextY][nextX])
                {
                    visited[nextY][nextX] = true;
                    q.push({nextY, nextX});
                    count++;
                }
            }
        }
    }
    return count;
}