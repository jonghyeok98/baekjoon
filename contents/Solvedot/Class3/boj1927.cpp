// boj s2 1927
// 최소 힙
#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i=0; i<N; i++)
	{
		int tmp;
		cin >> tmp;
		if(tmp==0)
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
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




