// boj s1 5525
// IOIOI

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

using int32 = long;
using int64 = long long;


 
int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    string input;
    cin >> input;

    int result=0;
    for(int i=0; i<M-1; i++)
    {
        if(input[i]=='O')
            continue;

        int count=0;

        while(input[i+1]=='O' && input[i+2]=='I')
        {
            count++;

            if(count==N)
            {
                result++;
                count--;
            }
            i+=2;
        }
    }
    
    cout << result;
    
    return 0;
}
