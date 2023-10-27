// boj s4 1764
// 듣보잡

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <string>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	unordered_set<string> name1;
	unordered_set<string> name2;
	set<string> v;
	int count = 0;

	for(int i=0; i<N; i++)
	{
		string temp;
		cin >> temp;
		name1.insert(temp);
	}

	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		name2.insert(temp);
	}

	for(string name : name1)
	{
		if (name2.find(name) != name2.end())
		{
			count++;
			v.insert(name);
		}
	}

	cout << count << '\n';
	
	for (string name : v)
		cout << name << '\n';
	
	return 0;
}


