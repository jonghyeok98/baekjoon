#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int count = 0;
	cin >> N;

	vector<int> v(N, 0);
	vector<int> s(N, 0);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	for (int i = 1; i < N; i++)
	{
		int tmp = v[i];
		int j = i;
		while (j>=1 && v[j - 1] > tmp)
		{
			v[j] = v[j - 1];
			j--;
		}
		v[j] = tmp;
	}

	s[0] = v[0];

	for (int i = 1; i < N; i++)
	{
		s[i] = s[i-1] + v[i];
	}

	for (int i = 0; i < N; i++)
	{
		count += s[i];
	}

	cout << count;

	return 0;
}
