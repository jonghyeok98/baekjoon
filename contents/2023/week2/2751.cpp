// boj s5 2751 수 정렬하기 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> arr;
	int N, num;
	cin >> N;

	arr.resize(N);

	for(int i=0; i<N; i++)
	{
		cin >> num;
		arr[i] = num;
	}

	sort(arr.begin(), arr.end());

	for (auto it : arr)
		cout << it << '\n';

	return 0;
}