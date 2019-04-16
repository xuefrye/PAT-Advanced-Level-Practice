/*
1069 The Black Hole of Numbers ��20 �֣�
ע���.
1.ʱ�̱������ֶ���4λ��,������λ��ǰ��0;
���������������С��4λ��,��û�в��㵼�½��������
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