/*
1087 All Roads Lead to Rome （30 分）

注意点
1.我用了50分钟飞速的写完这题。幸好中间没出问题.
2.还是要认真读题!
*/
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

const int inf = 0x3fffffff;
const int maxn = 300;
int n, k; string scity; int scityId;
string c,c1, c2; int cint, c1int, c2int;

map<string, int> name2int;
map<int, string> int2name;
int weight[maxn];
int G[maxn][maxn] = { 0 };
int visited[maxn] = { false };
int cost[maxn];
vector<int> pre[maxn];
int startid, endid;
vector<int> path, optPath;
int pathcnt=0;
int anshappy;
double ansavghappy;

int idCnt = 0;
int toint(string &name)
{
	if (name2int.find(name) != name2int.end())
		return name2int[name];
	else
	{
		name2int[name] = idCnt;
		int2name[idCnt] = name;
	}
	return idCnt++;
}

void djsk(int start)
{
	fill(cost, cost + maxn, inf);
	int now = start;
	cost[now] = 0;

	for (int i = 0; i < n; i++)
	{
		visited[now] = true;
		for (int j = 0; j < n; j++)
		{
			if (visited[j] == false && G[now][j] != 0)
			{
				if (cost[now] + G[now][j] < cost[j])
				{
					cost[j] = cost[now] + G[now][j];
					pre[j].clear();
					pre[j].push_back(now);
				}
				else if (cost[now] + G[now][j] == cost[j])
				{
					pre[j].push_back(now);
				}
			}
		}

		int minId = -1, minCost = inf;
		for (int j = 0; j < n; j++)
		{
			if (visited[j] == false && cost[j] < minCost)
			{
				minId = j;
				minCost = cost[j];
			}
		}
		if (minId == -1) return;
		now = minId;
	}
}

void dfs(int id)
{
	if (id == startid)
	{
		pathcnt++;
		path.push_back(id);

		int happy = 0; double avghappy = 0;
		for (int i = 0; i < path.size(); i++)
		{
			happy += weight[path[i]];
		}
		avghappy = happy / ((double)path.size()-1); // -1?

		if (happy > anshappy)
		{
			anshappy = happy;
			optPath = path;
			ansavghappy = avghappy;
		}
		else if (happy == anshappy && avghappy > ansavghappy)
		{
			optPath = path;
			ansavghappy = avghappy;
		}
		path.pop_back();
		return;
	}

	path.push_back(id);
	for (int i = 0; i < pre[id].size(); i++)
	{
		dfs(pre[id][i]);
	}
	path.pop_back();

}
int main()
{
	cin >> n >> k >> scity;
	scityId = toint(scity);
	for (int i = 0; i < n - 1; i++)
	{
		string c; int cweight;
		cin >> c >> cweight;
		cint = toint(c);
		weight[cint] = cweight;
	}
	for (int i = 0; i < k; i++)
	{
		int ccost;
		cin >> c1 >> c2 >> ccost;
		c1int = toint(c1);
		c2int = toint(c2);
		G[c1int][c2int] = G[c2int][c1int] = ccost;
	}

	startid = name2int[scity];
	endid = name2int["ROM"];
	djsk(startid);
	dfs(endid);
	printf("%d %d %d %d\n", pathcnt, cost[endid], anshappy, (int)ansavghappy);

	bool first = true;
	for (int i = optPath.size() - 1; i >= 0; i--)
	{
		if (first)
		{
			printf("%s", int2name[optPath[i]].c_str());
			first = false;
		}
		else
			printf("->%s", int2name[optPath[i]].c_str());
	}


	system("pause");
}