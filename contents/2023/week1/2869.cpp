// boj 2869 달팽이는 올라가고 싶다

#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);

	long long a, b, v, result;
	cin >> a >> b >> v;
	if ((v - a) % (a - b) == 0)
		cout << (v - a) / (a - b) + 1;
	else
		cout << (v - a) / (a - b) + 2;
	
	return 0;
}

