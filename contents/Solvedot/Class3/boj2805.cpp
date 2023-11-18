// boj s2 2805
// 나무 자르기
#include<iostream>
#include<vector>

using namespace std;

static vector<long long> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    v.resize(N);
    long long max=0;
    long long min=0;
    
    for(int i=0; i<N; i++)
    {
        cin >> v[i];

        if(v[i]>max)
            max=v[i];
    }

    while(max>=min)
    {
        long long sum=0;
        long long mid=(min+max)/2;

        for(int i : v)
        {
            if(i-mid>0)
                sum+=i-mid;
        }

        if(sum>=M)
            min=mid+1;
        else
            max=mid-1;
    }
    if(max<0)
        max=0;
    cout << max;

    return 0;
}
