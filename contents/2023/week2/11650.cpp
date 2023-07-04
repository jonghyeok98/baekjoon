// boj s5 11650 좌표 정렬하기
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Pos
{
	int x=0;
	int y=0;
};

bool compare(Pos p1, Pos p2);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, a, b;
	cin >> N;

	vector<Pos> arr;

	for(int i=0; i<N; i++)
	{
		cin >> a >> b;
		arr.push_back(Pos{ a, b });
	}

	sort(arr.begin(), arr.end(), compare);

	for (auto it : arr)
		cout << it.x << ' ' << it.y << '\n';

	return 0;
}


bool compare(Pos p1, Pos p2)
{
	if (p1.x == p2.x)
		return p1.y < p2.y;

	return p1.x < p2.x;
}
