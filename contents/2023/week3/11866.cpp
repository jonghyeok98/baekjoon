// boj s5 11866 요세푸스 문제0

#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, tmp;
	cin >> N >> K;

	queue<int> q;
	for (int i = 1; i <= N; i++)
		q.push(i);

	cout << "<";

	while(true)
	{
		if (q.empty())
			break;
		for(int i=1; i<=K; i++)
		{
			if(i!=K)
			{
				tmp = q.front();
				q.pop();
				q.push(tmp);
			}
			else
			{
				cout << q.front();
				q.pop();
				if (!q.empty())
					cout << ", ";
			}
		}
	}
	cout << ">";
	return 0;
}

