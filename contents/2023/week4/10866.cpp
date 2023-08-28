// boj s4 10866 덱
#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	string input;
	deque<int> dq;
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		cin >> input;

		if (input == "push_front")
		{
			int tmp;
			cin >> tmp;
			dq.push_front(tmp);
		}
		else if (input == "push_back")
		{
			int tmp;
			cin >> tmp;
			dq.push_back(tmp);
		}
		else if (input == "pop_front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else
				cout << -1 << '\n';
		}
		else if (input == "pop_back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else
				cout << -1 << '\n';
		}
		else if (input == "size")
			cout << dq.size() << '\n';
		else if (input == "empty")
			cout << dq.empty() << '\n';
		else if (input == "front")
		{
			if (!dq.empty())
				cout << dq.front() << '\n';
			else
				cout << -1 << '\n';
		}
		else if(input=="back")
		{
			if (!dq.empty())
				cout << dq.back() << '\n';
			else
				cout << -1 << '\n';
		}
	}


	return 0;
}

