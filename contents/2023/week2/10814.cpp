// boj s5 10814 나이순 정렬
// age, name으로 이루어진 구조체를 만들어 sort를 사용하면
// 메모리와 시간을 더욱 더 절약할 수 있다

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
	multimap<int, string> customer;
	int N;
	int age;
	string name;
	cin >> N;

	for(int i=0; i<N; i++)
	{
		cin >> age >> name;
		customer.insert(make_pair(age, name));
	}

	for (auto it : customer)
		cout << it.first << ' ' << it.second << '\n';
	
	return 0;
}