// boj s4 1920 수 찾기
#include <iostream>
#include <unordered_set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M, n;
	cin >> N;

	unordered_set<int> s1;
	unordered_set<int> s2;

	for(int i=0; i<N; i++)
	{
		cin >> M;
		s1.insert(M);
	}

	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> M;
		if (s1.find(M) != s1.end())
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	// 이 방법은 왜 안될까?
	/*cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> M;
		s2.insert(M);
	}
	
	for (auto it : s2)
	{
		if (s1.find(it) == s1.end())
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}*/
	

	return 0;
}

