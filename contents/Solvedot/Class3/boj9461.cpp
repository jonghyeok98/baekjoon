// boj s3 9416
// 파도반 수열

#include<iostream>

using namespace std;

static long long P[101] = {0};

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int T;
    cin >> T;

    P[1]=1;
    P[2]=1;

    for(int i=3; i<101; i++)
    {
        P[i]=P[i-3]+P[i-2];
    }

    for(int i=0; i<T; i++)
    {
        int N;
        cin >> N;

        cout << P[N] << '\n';
    }

    return 0;
}