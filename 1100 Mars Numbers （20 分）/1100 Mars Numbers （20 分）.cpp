/*
1100 Mars Numbers £¨20 ·Ö£©
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n;
string in,in2;
string ge[]= { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string shi[] = { "&&&&","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
void toMar(string s)
{
	int num = stoi(s);
	if (num / 13 != 0)
		cout << shi[num / 13];
	if (num / 13 != 0 && num % 13 != 0)
		cout << " ";
	if (num % 13 != 0 || num==0)
		cout << ge[num % 13];
	cout << endl;
}

void toEarth(string s)
{
	int g=0, sh=0;
	string s1 = s.substr(0, 3); string s2;
	if (s.size() > 4)
	{
		s2 = s.substr(4, 3);
	}
	for (int i = 0; i < 13; i++)
	{
		if (s1 == ge[i] || s2 == ge[i]) g = i;
		if (s1 == shi[i]) sh = i;
	}
	cout << g + sh * 13 << endl;

}


int main()
{
	cin >> n; getchar();
	for (int i = 0; i < n; i++)
	{
		getline(cin, in);
		if (in[0] >= '0' && in[0] <= '9')
		{
			toMar(in);
		}
		else
		{
			toEarth(in);
		}
	}
	system("pause");
}