// boj s2 11279
// 최대 힙
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

static priority_queue<int> pq;

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N;
    cin >> N;

    for(int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;

        if(tmp==0)
        {
            if(pq.empty())
                cout << 0 << '\n';
            else
            {
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(tmp);
        }
    }

    return 0;
}
