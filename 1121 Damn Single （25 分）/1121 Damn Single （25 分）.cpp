/*
1121 Damn Single £¨25 ·Ö£©
*/

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int m, n;
int id1, id2, id;
unordered_map<int, int> couple;
vector<int> member;
vector<int> ans;
int h[maxn] = { false };
bool paired[maxn] = { false };
int findCouple(vector<int> &v, int &id)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == id)
			return i;
	}
	return -1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &id1, &id2);
		couple[id1] = id2; couple[id2] = id1;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> id;
		member.push_back(id);
	}

	for (int i = 0; i < member.size(); i++)
	{
		if (paired[i] == false)
		{
			int idx = findCouple(member, couple[member[i]]);
			if (idx != -1)
			{
				paired[i] = paired[idx] = true;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (paired[i] == false)
			ans.push_back(member[i]);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	bool first = true;

	for (auto each : ans)
	{
		if (first)
		{
			printf("%05d", each);
			first = false;
		}
		else
			printf(" %05d", each);
	}
	system("pause");
}