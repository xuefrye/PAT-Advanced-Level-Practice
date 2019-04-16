/*
1005 Spell It Right £¨20 ·Ö£©
*/

#include<iostream>
#include<string>
using namespace std;

string num[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
string in;
int sum = 0;
int main()
{
	cin >> in;
	for (int i = 0; i < in.size(); i++)
		sum += in[i]-'0';

	in = to_string(sum);
	bool first = true;
	for (int i = 0; i < in.size(); i++)
	{
		if (first)
		{
			printf("%s", num[stoi(in.substr(i, 1))].c_str()); first = false;
		}
		else
			printf(" %s", num[stoi(in.substr(i, 1))].c_str());
	}
	system("pause");
}
