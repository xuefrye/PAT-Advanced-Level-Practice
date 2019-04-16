/*
1112 Stucked Keyboard £¨20 ·Ö£©
*/
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int k;
string in;
map<char, int> stuck;
vector<char> ans;

bool cmp(char a, char b)
{
	return in.find(a) < in.find(b);
}

int main()
{
	cin >> k >> in;
	int cnt = 1;
	for (int i = 0,j; i < in.size()-1; i=j)
	{
		for (j = i + 1; j < in.size() && in[i] == in[j]; j++);

		int len = j - i;
		if (len%k == 0 && stuck[in[i]] != -1)
		{
			stuck[in[i]] = 1;
		}
		else
		{
			stuck[in[i]] = -1;
		}
	}

	for (auto each : stuck)
	{
		if (each.second == 1)
		{
			ans.push_back(each.first);
		}
	}

	set<char> visited;
	sort(ans.begin(), ans.end(),cmp);
	for (auto each : ans)
	{
		cout << each;
		visited.insert(each);
	}
	cout << endl;

	for (int i = 0; i < in.size(); i++)
	{
		cout << in[i];
		if (visited.find(in[i]) != visited.end())
			i += k-1;
	}
}