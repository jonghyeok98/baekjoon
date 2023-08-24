// boj s4 10773 제로
#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, tmp, ans=0;
	cin >> N;

	stack<int> s;

	for(int i=0; i<N; i++)
	{
		cin >> tmp;
		if (tmp == 0 && !s.empty())
			s.pop();
		else
			s.push(tmp);
	}

	while(!s.empty())
	{
		ans += s.top();
		s.pop();
	}

	cout << ans;

	return 0;
}

