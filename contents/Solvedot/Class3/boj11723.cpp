// boj s5 11723
// 집합

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<bool> arr(21, false);
	
	for(int i=0; i<N; i++)
	{
		string input;
		cin >> input;
		cin.ignore();
		
		int tmp;
		if(input == "add")
		{
			cin >> tmp;
			cin.ignore();
			arr[tmp] = true;
		}
		else if(input == "check")
		{
			cin >> tmp;
			cin.ignore();
			if (arr[tmp])
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if(input=="remove")
		{
			cin >> tmp;
			cin.ignore();
			arr[tmp] = false;
		}
		else if(input=="toggle")
		{
			cin >> tmp;
			cin.ignore();
			arr[tmp] = !arr[tmp];
		}
		else if(input=="all")
		{
			fill(arr.begin(), arr.end(), true);
		}
		else if(input=="empty")
		{
			fill(arr.begin(), arr.end(), false);
		}

	}
	
	return 0;
}


