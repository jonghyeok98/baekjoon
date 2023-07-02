// boj 1259 팰린드롬수

#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	queue<string> input;
	string tmp;
	int size;
	bool flag = true;

	while(!cin.eof())
	{
		cin >> tmp;
		if (tmp == "0")
			break;
		input.push(tmp);
	}

	while (!input.empty())
	{
		flag = true;
		tmp = input.front();
		input.pop();
		size = tmp.size();
		for(int j=0; j<=tmp.size()/2; j++)
		{
			if (tmp[j] != tmp[size-1])
			{
				flag = false;
				cout << "no" << '\n';
				break;
			}
			size--;
		}
		if(flag)
			cout << "yes" << '\n';
	}
	
	
	return 0;
}