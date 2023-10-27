// boj s4 17219
// 비밀번호 찾기

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	unordered_map<string, string> pw;

	for(int i=0; i<N; i++)
	{
		string site, password;
		cin >> site >> password;
		pw.insert({ site, password });
	}

	for(int i=0; i<M; i++)
	{
		string site;
		cin >> site;
		cout << pw[site] << '\n';
	}

	// C++ 17에서 map key와 value 탐색
	/*for(auto const& [key, val] : pw)
	{
		cout << key << " " << val << "\n";
	}*/

	
	return 0;
}


