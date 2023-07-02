// boj s5 1676 팩토리얼 0의 개수

// 팩토리얼은 숫자가 조금만 커져도 값이 매우 커지기 때문에 단순 계산으로 하면 오버플로우가 발생한다
// 처음 0이 아닌 숫자가 나올때까지의 0은 10의 거듭제곱꼴이 곱해져있음을 나타낸다
// 10은 2와 5의 곱으로 인수분해가 가능하고 2와 5가 몇 개 있는지를 구해야한다
// 2^3 * 5^2 = 10^2 * 2 이기 때문에 적은 쪽의 개수를 찾으면 된다
#include <iostream>

using namespace std;

void find_count(int a);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	find_count(N);

	return 0;
}

void find_count(int a)
{
	int cnt2 = 0;
	int cnt5 = 0;
	int tmp;
	for(int i=2; i<=a; i++)
	{
		tmp = i;
		while(tmp%2==0)
		{
			cnt2++;
			tmp /= 2;
		}
		while(tmp%5==0)
		{
			cnt5++;
			tmp /= 5;
		}
	}
	cout << min(cnt2, cnt5);
}
