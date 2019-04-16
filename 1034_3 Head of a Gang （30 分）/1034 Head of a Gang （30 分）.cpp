/*
1034 Head of a Gang （30 分）
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

const int maxn = 2020;
int n, k, t;
string n1, n2;
int n1id, n2id;
int idcnt=0;
map<string, int> name2int;
map<int, string> int2name;
vector<int> adj[maxn];
int nodeweight[maxn] = { 0 };
bool visited[maxn] = { false };

struct gang
{
	string head;
	int membercnt;
	gang(string h,int m):head(h),membercnt(m){}
};

bool cmp(gang &a, gang &b)
{
	return a.head < b.head;
}

int toint(string &str)
{
	if (name2int.find(str) == name2int.end())
	{
		name2int[str] = idcnt;
		int2name[idcnt] = str;
		return idcnt++;
	}
	else
		return name2int[str];
}

string tostring(int &i)
{
	return int2name[i];
}

void dfs(int id, int &headid, int &member,int &sumweight)
{
	visited[id] = true;
	sumweight += nodeweight[id];
	member++;
	if (nodeweight[id] > nodeweight[headid])
		headid = id;

	for (int i = 0; i < adj[id].size(); i++)
	{
		if(visited[adj[id][i]] == false)
			dfs(adj[id][i], headid, member,sumweight);
	}
}


void travel()
{
	int headid, membercnt ,sumweight, gangcnt=0;
	vector<gang> gangs;
	for (int id = 0; id < n; id++)
	{
		if (visited[id] == false)
		{
			headid = id;
			membercnt = sumweight = 0;
			dfs(id, headid, membercnt, sumweight);

			if (membercnt > 2 && sumweight/2 > k) //由于对每个节点加了两次通话时间，这里除以2
			{
				string head = tostring(headid);
				gangs.push_back(gang(head, membercnt));
				gangcnt++;
			}
		}
	}

	sort(gangs.begin(), gangs.end(), cmp);
	printf("%d\n", gangcnt);
	for (auto each : gangs)
	{
		printf("%s %d\n", each.head.c_str(), each.membercnt);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		cin >> n1 >> n2 >> t;
		n1id = toint(n1); n2id = toint(n2);
		nodeweight[n1id] += t; nodeweight[n2id] += t;
		adj[n1id].push_back(n2id); adj[n2id].push_back(n1id);
	}
	travel();
	system("pause");
}