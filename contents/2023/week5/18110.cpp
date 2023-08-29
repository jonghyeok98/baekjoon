// boj s4 18110 solved.ac

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, ans=0, result;
	cin >> N;

	if(N==0)
	{
		cout << 0;
		return 0;
	}
	
	int tm =round(N*0.15);
	vector<int> v;

	for(int i=0; i<N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for(int i = tm; i<N-tm; i++)
	{
		ans += v[i];
	}


	result= round((ans*1.0) / (N - (2 * tm)));
	cout << result;
	return 0;
}

