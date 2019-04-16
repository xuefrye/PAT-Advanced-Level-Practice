/*
1112 Stucked Keyboard £¨20 ·Ö£©
*/
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>
using namespace std;
//map<char, bool> stuck;
vector<char> stuck;
string in;
int rep;
set<char> ans;

bool is_stuck(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[0] != str[i])
			return false;
	}
	return true;
}

int main()
{
	cin >> rep >> in;
	for (int i = 0; i < in.size() - rep; i++)
	{
		if (is_stuck(in.substr(i, rep)))
		{
			stuck.push_back(in[i]);
		}
	}
	for (int j = 0; j < stuck.size(); j++)
	{
		for (int i = 0; i < in.size(); i++)
		{
			if (in[i] == stuck[j])
			{
				int cnt = 1, flag = true;
				while (1)
				{
					if (in[++i] == stuck[j])
						cnt++;
					else
						break;
				}
				if (cnt < rep)
					stuck.erase(stuck.begin()+(j--));
			}
		}
	}
	vector<int> ans1;
	for (auto each : stuck)
	{
		if (ans.find(each) == ans.end())
		{
			cout << each;
			ans1.push_back(each);
			ans.insert(each);
		}
	}
	cout << endl;
	for (int i = 0; i < in.size(); i++)
	{
		cout << in[i];
		if (ans.find(in[i]) != ans.end())
		{
			i += 2;
		}
	}
}