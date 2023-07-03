// boj s5 7568 덩치
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(void)
{
	vector<int> height;
	vector<int> weight;
	vector<int> rank;
	int N, a, b;
	cin >> N;

	height.resize(N);
	weight.resize(N);
	rank.resize(N, 1);
	for(int i=0; i<N; i++)
	{
		cin >> a >> b;
		weight[i] = a;
		height[i] = b;
	}

	for(int i =0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(i!=j)
			{
				if((weight[i]<=weight[j] && height[i]<=height[j]) && ((weight[i] != weight[j]) && height[i] != height[j]))
				{
					rank[i]++;
				}
			}
		}
	}

	for (auto it : rank)
		cout << it << ' ';
	return 0;
}