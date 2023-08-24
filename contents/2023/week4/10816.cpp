// boj s4 10816 숫자카드2
// algorithm의 upper_bound, lower_bound 활용
// upper_bound: 타깃의 초과하는 인덱스
// lower_bound: 타깃의 최소 인덱스
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, tmp;
	vector<int> v;
	
	cin >> N;

	for(int i=0; i<N; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	cin >> M;
	for(int i=0; i<M; i++)
	{
		cin >> tmp;
		cout << upper_bound(v.begin(), v.end(), tmp) - lower_bound(v.begin(), v.end(), tmp) << ' ';
	}

	return 0;
}

