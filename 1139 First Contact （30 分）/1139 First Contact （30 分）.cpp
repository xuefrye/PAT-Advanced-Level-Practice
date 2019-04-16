/*
1139 First Contact £¨30 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 1000;

struct node {
	int fname1;
	int fname2;
};

int cmp(node &a, node &b)
{
	if (a.fname1 != b.fname1)
		return a.fname1 < b.fname1;
	else
		return a.fname2 < b.fname2;
}
unordered_map<string, int> name2id;
unordered_map<int, string> id2name;
int n, m, k, id1, id2;
string name1, name2;
vector<int> adj[maxn];
vector<node> ans;


int idCnt = 0;
int toId(string name)
{
	if (name2id.find(name) == name2id.end())
	{
		name2id[name] = idCnt;
		id2name[idCnt] = name;
		return idCnt++;
	}
	else
		return name2id[name];
}

int getGender(string name)
{
	if (name[0] =='-') return -1;
	else return 1;
}

void dfs1(int id1,int id2)
{
	string name1 = id2name[id1];
	string name2 = id2name[id2];
	for (int i = 0; i< adj[id1].size(); i++)
	{
		int fid = adj[id1][i]; string fname = id2name[fid];
		if (getGender(fname) == getGender(name1))
		{
			for (int x = 0; x < adj[fid].size(); x++)
			{
				int ffid = adj[fid][x]; string ffname = id2name[ffid];
				if (getGender(ffname) != getGender(fname))
				{
					for (int y = 0; y < adj[ffid].size(); y++)
					{
						if (getGender(name2) == getGender(ffname))
						{
							if (adj[ffid][y] == id2)
							{
								ans.push_back(node{ abs(stoi(id2name[fid])),abs(stoi(id2name[ffid])) });
							}
						}
					}
				}
			}
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%04d %04d\n", ans[i].fname1, ans[i].fname2);
	}
	ans.clear();
}

void dfs2(int id1, int id2)
{
	string name1 = id2name[id1];
	string name2 = id2name[id2];
	for (int i = 0; i < adj[id1].size(); i++)
	{
		int fid = adj[id1][i]; string fname = id2name[fid];
		if (getGender(fname) == getGender(name1))
		{
			for (int x = 0; x < adj[fid].size(); x++)
			{
				int ffid = adj[fid][x]; string ffname = id2name[ffid];
				if (getGender(ffname) == getGender(fname))
				{
					for (int y = 0; y < adj[ffid].size(); y++)
					{
						if (getGender(name2) == getGender(ffname))
						{
							if (adj[ffid][y] == id2 && fname != name2 && ffname != name2)
							{
								ans.push_back(node{ abs(stoi(id2name[fid])),abs(stoi(id2name[ffid])) });
							}
						}
					}
				}
			}
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%04d %04d\n", ans[i].fname1, ans[i].fname2);
	}
	ans.clear();
}
int main()
{
	//freopen("1139.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> name1 >> name2;
		id1 = toId(name1); id2 = toId(name2);
		adj[id1].push_back(id2);
		adj[id2].push_back(id1);
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> name1 >> name2;
		id1 = toId(name1); id2 = toId(name2);
		if (getGender(name1) != getGender(name2))
			dfs1(id1, id2);
		else
			dfs2(id1, id2);
	}

	system("pause");
}