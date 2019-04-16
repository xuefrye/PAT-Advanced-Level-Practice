/*
1069 The Black Hole of Numbers （20 分）
注意点.
1.时刻保持数字都是4位数,不足四位补前导0;
比如两数相减后结果小于4位数,我没有补零导致结果出问题
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
bool cmp(char &a, char &b)
{
	return a > b;
}

int main()
{
	string s;
	cin >> s;
	s.insert(0,4-s.size(),'0');
	do
	{
		string a = s, b = s;
		sort(a.begin(), a.end(), cmp);
		sort(b.begin(), b.end());
		printf("%04d - %04d = %04d\n", stoi(a), stoi(b), stoi(a) - stoi(b));
		s = to_string(stoi(a) - stoi(b));
		s.insert(0, 4 - s.size(), '0');
	} while (s != "6174" && s != "0000");

	system("pause");
}