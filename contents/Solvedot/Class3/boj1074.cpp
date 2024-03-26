// boj s1 1074
// Z
#include <iostream>

using namespace std;

static int N, r, c;
static int result = 0;

void solve(int x, int y, int size)
{
	if (r == x && c == y)
	{
		cout << result;
		return;
	}

	if (r < x + size && c < y + size && r >= x && c >= y)
	{
		solve(x, y, size / 2);
		solve(x, y + size / 2, size / 2);
		solve(x + size / 2, y, size / 2);
		solve(x + size / 2, y + size / 2, size / 2);
	}
	else
	{
		result += size * size;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> r >> c;

	solve(0, 0, (1 << N));

	return 0;
}

