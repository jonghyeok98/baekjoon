// boj s5 1181 단어정렬 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int cmp(string a, string b);

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> word;
	
	string input;
	int N;
	cin >> N;

	word.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		word.push_back(input);
	}

	sort(word.begin(), word.end(), cmp);

	for (int i=1; i<word.size(); i++)
	{
		if ( word[i] == word[i -1])
			continue;
		cout << word[i] << '\n';
	}
		
	return 0;
}

int cmp(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	else
	{
		return a.length() < b.length();
	}
}