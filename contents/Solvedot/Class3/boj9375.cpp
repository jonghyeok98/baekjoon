// boj s3 9375
// 패션왕 신해빈
// 옷이 3개가 있다면 3개를 입는 경우 + 안입는 경우 1개 = 4가지 경우
// (의상의 개수 +1)*(모든 의상 종류 개수 +1) -1(모두 안입는경우)

#include<iostream>
#include<unordered_map>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int T;
    cin >> T;

    for(int i=0; i<T; i++)
    {
        int N;
        cin >> N;
        unordered_map<string, int> wear;
        for(int j=0; j<N; j++)
        {
            string key, value;
            cin >> key >> value;
            wear[value]++;
        }
        int result=1;
        for(auto const& [key, val] : wear)
        {
            result*=(val+1);
        }
        cout << result-1 << '\n';
    }

    return 0;
}