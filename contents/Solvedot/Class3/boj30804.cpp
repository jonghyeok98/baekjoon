// boj s2 30804 과일 탕후루
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N;
    cin >> N;

    int result=0;
    vector<int> v(N, 0);
    vector<int> c(10, 0);
    
    for(int i=0; i<N; i++)
        cin >> v[i];

    int l=0, r=0;
    while(r<N)
    {
        c[v[r++]]++;
        while(10 - count(c.begin(), c.end(), 0) > 2)
            c[v[l++]]--;
        result = max(result, r-l);
    }
    cout << result;
    
    return 0;
}

