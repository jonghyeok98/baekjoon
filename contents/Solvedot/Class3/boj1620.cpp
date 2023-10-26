// boj s4 1620
// 나는야 포켓몬 마스터 이다솜

#include <iostream>
#include <unordered_map>
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


	unordered_map<string, string> dict;
	vector<string> pokemon(N+1);
	

	for(int i=1; i<=N; i++)
	{
		string temp;
		cin >> temp;
		dict.insert({ temp, to_string(i)});
		pokemon[i] = temp;
	}

	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;

		if (dict.find(temp) != dict.end())
			cout << dict[temp] << '\n';
		else
			cout << pokemon[stoi(temp)] << '\n';
		
	}
	
	
	return 0;
}


