// boj s4 9012 괄호

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	cin.ignore();

	for(int i=0; i<N; i++)
	{
		string input;
		stack<char> s;
		bool flag=false;
		char c;

		getline(cin, input);

		for(int j=0; j<input.length(); j++)
		{
			c = input[j];
			if (c == '(')
				s.push(c);
			else if(c==')')
			{
				if (!s.empty())
					s.pop();
				else
				{
					flag = true;
					break;
				}
			}
		}
		if (flag == false && s.empty())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

	}
	
	return 0;
}

