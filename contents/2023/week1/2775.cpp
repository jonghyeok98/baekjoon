// boj 2775 부녀회장이 될테야

#include<iostream>

using namespace std;

int arr[14] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
int sum = 0;
void find_num(int a, int b);

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	int N, a, b;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		sum = 0;
		cin >> a >> b;
		find_num(a, b-1);
		cout << sum << '\n';
	}
	
	
	return 0;
}

void find_num(int a, int b)
{
	if (a == 0)
		sum += arr[b];
	else
	{
		for(int i=0; i<=b; i++)
			find_num(a - 1, i);
	}
		
}
