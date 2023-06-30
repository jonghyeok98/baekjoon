// boj s5 1436 영화감독 숌
// 666으로 나누어 떨어지면 종말의 수

#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num=0, count=0, tmp;
	cin >> N;

    // N번째 종말의 수라면 탈출
	while(count != N)
	{
		num++;
		tmp = num;
		while(tmp!=0)
		{
            // 666으로 나누어 떨어지면 종말의 수 이므로 
			if (tmp % 1000 == 666)
			{
                // 몇번째 종말의 수인지 count
				count++;
				break;
			}
			else
			{
                // 나누어 떨어지지 않으면 10으로 계속해서 나누어 간다
                // 계속 나누어 0이 되었다면 종말의 수 X
				tmp /= 10;
			}
		}
	}
    
	cout << num;
		
	return 0;
}

