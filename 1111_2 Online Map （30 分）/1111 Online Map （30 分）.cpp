/*
1111 Online Map £¨30 ·Ö£©
*/

#include<iostream>
//#include<map>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1000;
const int inf = 0x3fffffff;
vector<int> adj[maxn];
int t[maxn][maxn], d[maxn][maxn];
vector<int> timePath, disPath,path;
int minTime = inf, minDis = inf, minNode = inf;
int n, m, v1, v2, oneWay, l, t1, s, e;
bool visited[maxn] = { false };
int dis[maxn];
int tim[maxn];
vector<int> pre[maxn];

void djskDis(int s)
{
	fill(visited, visited + maxn, false);
	fill(dis, dis + maxn, inf);

	dis[s] = 0;
	visited[s] = true;
	int now = s;
	for (int i = 0; i < n; i++)
	{
		visited[now] = true;
		for (int j = 0; j < n; j++)
		{
			if (visited[j]==false && d[now][j] != 0)
			{
				if (dis[j]> dis[now] + d[now][j])
				{
					dis[j] = dis[now] + d[now][j];
					pre[j].clear();
					pre[j].push_back(now);
				}
				else if(dis[j] == dis[now] + d[now][j])
				{
					pre[j].push_back(now);
				}
			}
		}

		int minDis = inf, minIdx = -1;
		for (int j = 0; j < n; j++)
		{
			if (visited[j] == false && dis[j]<minDis)
			{
				minDis = dis[j];
				minIdx = j;
			}
		}

		if (minIdx == -1)
			return;
		now = minIdx;
	}
}

void djskTim(int s)
{
	fill(visited, visited + maxn, false);
	fill(tim, tim + maxn, inf);

	tim[s] = 0;
	visited[s] = true;
	int now = s;
	for (int i = 0; i < n; i++)
	{
		visited[now] = true;
		for (int j = 0; j < n; j++)
		{
			if (visited[j] == false && t[now][j] != 0)
			{
				if (tim[j] > tim[now] + t[now][j])
				{
					tim[j] = tim[now] + t[now][j];
					pre[j].clear();
					pre[j].push_back(now);
				}
				else if (tim[j] == tim[now] + t[now][j])
				{
					pre[j].push_back(now);
				}
			}
		}

		int minDis = inf, minIdx = -1;
		for (int j = 0; j < n; j++)
		{
			if (visited[j] == false && tim[j] < minDis)
			{
				minDis = tim[j];
				minIdx = j;
			}
		}

		if (minIdx == -1)
			return;
		now = minIdx;
	}
}


void dfsDis(int e)
{
	if (pre[e].size() == 0)
	{
		path.push_back(e);
		int totalTime = 0;
		for (int i = path.size()-1; i >=1; i--)
		{
			totalTime += t[path[i]][path[i - 1]];
		}
		if (totalTime < minTime)
		{
			minTime = totalTime;
			disPath = path;
		}
		path.pop_back();
		return;
	}
	path.push_back(e);
	for (int i = 0; i < pre[e].size();i++)
	{
		dfsDis(pre[e][i]);
	}
	path.pop_back();
}

void dfsTim(int e)
{
	if (pre[e].size() == 0)
	{
		path.push_back(e);
		int totalNode = path.size();

		if (totalNode < minNode)
		{
			minNode = totalNode;
			timePath = path;
		}
		path.pop_back();
		return;
	}

	path.push_back(e);
	for (int i = 0; i < pre[e].size(); i++)
	{
		dfsTim(pre[e][i]);
	}
	path.pop_back();
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> oneWay >> l >> t1;
		t[v1][v2] = t1;
		d[v1][v2] = l;
		adj[v1].push_back(v2);
		if (!oneWay)
		{
			adj[v2].push_back(v1);
			t[v2][v1] = t1;
			d[v2][v1] = l;
		}
	}

	cin >> s >> e;
	djskDis(s);
	dfsDis(e);

	minTime = inf, minDis = inf, minNode = inf;
	djskTim(s);
	dfsTim(e);

	reverse(timePath.begin(), timePath.end());
	reverse(disPath.begin(), disPath.end());
	if (timePath == disPath)
	{
		printf("Distance = %d; Time = %d:", dis[e], tim[e]);
		printf(" %d", timePath[0]);
		for (int i = 1; i < timePath.size(); i++)
			printf(" -> %d", timePath[i]);
	}
	else
	{
		printf("Distance = %d:", dis[e]);
		printf(" %d", disPath[0]);
		for (int i = 1; i < disPath.size(); i++)
			printf(" -> %d", disPath[i]);

		printf("\nTime = %d:", tim[e]);
		printf(" %d", timePath[0]);
		for (int i = 1; i < timePath.size(); i++)
			printf(" -> %d", timePath[i]);
	}

	system("pause");
}