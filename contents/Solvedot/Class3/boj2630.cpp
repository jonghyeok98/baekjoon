// boj s2 2630
// 색종이 만들기
#include <iostream>
#include <vector>

using namespace std;

static vector<vector<bool>> v;
static int N;

static int white = 0;
static int blue = 0;

void countPaper(int x, int y, int size);
int check(int x, int y, int size);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	
	v.resize(N, vector<bool>(N, false));

	for(int i=0; i<N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bool tmp;
			cin >> tmp;
			v[i][j] = tmp;
		}
			
	}

	countPaper(0, 0, N);
	cout << white << '\n' << blue;
	
	
	return 0;
}


void countPaper(int x, int y, int size)
{
	if(x>=0 && y>=0)
	{
		if (check(x, y, size)==1)
		{
			blue++;
			return;
		}

		if(check(x, y, size)==0)
		{
			white++;
			return;
		}

		size = size / 2;

		countPaper(x, y, size);
		countPaper(x + size, y, size);
		countPaper(x, y + size, size);
		countPaper(x + size, y + size, size);
		
	}
}

int check(int x, int y, int size)
{
	int flag = v[y][x];
	for(int i=y; i<y+size; i++)
	{
		for(int j=x; j<x+size; j++)
		{
			if (flag != v[i][j])
				return -1;
		}
	}
	return flag;
}




