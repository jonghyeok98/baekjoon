// boj s4 4949 균형잡힌 세상

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true)
	{
		string input;
		getline(cin, input);
		if (input == ".")
			break;

		stack<char> symbol;
		bool flag = false;
		char c;

		for(int i=0; i<input.length(); i++)
		{
			c = input[i];

			if ((c == '(') || (c == '['))
				symbol.push(c);
			else if((c==')'))
			{
				if (!symbol.empty() && symbol.top() == '(')
					symbol.pop();
				else
				{
					flag = true;
					break;
				}
			}
			else if(c==']')
			{
				if (!symbol.empty() && symbol.top() == '[')
					symbol.pop();
				else
				{
					flag = true;
					break;
				}
			}
		}
		if (flag == false && symbol.empty())
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';

	}
	
	return 0;
}

