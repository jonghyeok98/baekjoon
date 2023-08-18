// boj s4 1018 체스판 다시 칠하기
// brute force

#include <iostream>
#include <string>

using namespace std;

string WB[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

string BW[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

string board[50];

int CntWB(int x, int y);
int CntBW(int x, int y);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int minCnt = 65;

	int n, m, tmp;
	cin >> n >> m;
	cin.ignore();    // '\n'이 getline에 전달되기 떄문에 입력 버퍼를 비우기

	for (int i = 0; i < n; i++)
		getline(cin, board[i]);

	for(int i=0; i+8<=n; i++)
	{
		for(int j=0; j+8<=m; j++)
		{
			tmp = min(CntWB(i, j), CntBW(i, j));
			if (tmp < minCnt)
				minCnt = tmp;
		}
	}

	cout << minCnt;

	return 0;
}

int CntWB(int x, int y)
{
	int cnt=0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (WB[i][j] != board[x+i][y+j])
				cnt++;
		}
	}
	return cnt;
}

int CntBW(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (BW[i][j] != board[x+i][y+j])
				cnt++;
		}
	}
	return cnt;
}


