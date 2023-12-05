// boj s2 18870
// 좌표 압축
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static vector<pair<int, int>> v;
static vector<int> result;

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N;
    cin >> N;

    v.resize(N);
    result.resize(N);

    for(int i=0; i<N; i++)
    {
        cin >> v[i].first;
        v[i].second=i;
    }
        
    sort(v.begin(), v.end());

    result[v[0].second] = 0;
    int count = 1;
    for(int i=1; i<N; i++)
    {
        
        if(v[i-1].first == v[i].first)
            result[v[i].second] = result[v[i-1].second];
        else
        {
            result[v[i].second] = count;
            count ++;
        }
    }   

    for(int i : result)
        cout << i << " ";
    
    
    return 0;
}
