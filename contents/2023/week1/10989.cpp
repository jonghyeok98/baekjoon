// boj 10989 수 정렬하기 3
// 모든 수를 다 저장하면 메모리 초과가 뜨기 때문에
// 1~10000의 숫자를 카운트 해서 출력해야 함
#include<iostream>
#include<vector>

using namespace std;


int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    cin >> N;
    int arr[10001] = { 0 };

    // 숫자 개수 카운트
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr[a] += 1;
    }

    // 각 숫자를 개수만큼 출력해주기
    for (int i = 1; i <= 10000; i++)
        for (int j = 0; j < arr[i]; j++)
            cout << i << "\n";
	return 0;
}

