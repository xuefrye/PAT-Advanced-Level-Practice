/*
1018 Public Bike Management £¨30 ·Ö£©
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 510;
const int inf = 0x3fffffff;
int capacity, n, sp, m;
int st1, st2, t;
int G[maxn][maxn] = { 0 };
int visited[maxn] = {false};
int dis[maxn];
int dotweight[maxn];
vector<int> path, optPath;
vector<int> pre[maxn];
int minNeed = inf;
int minBring=inf;

void djsk(int start)
{
	fill(dis, dis + maxn, inf);
	int now = start;
	dis[now] = 0;
	
	for (int i = 0; i < n; i++)
	{
		visited[now] = true;
		for (int j = 0; j <= n; j++)
		{
			if (visited[j] == false && G[now][j] != 0)
			{
				if (dis[now] + G[now][j] < dis[j])
				{
					dis[j] = dis[now] + G[now][j];
					pre[j].clear();
					pre[j].push_back(now);
				}
				else if (dis[now] + G[now][j] == dis[j])
				{
					pre[j].push_back(now);
				}
			}
		}

		int minindex = -1, mindis = inf;
		for (int j = 0; j <= n; j++)
		{
			if (visited[j]==false && dis[j] < mindis)
			{
				mindis = dis[j];
				minindex = j;
			}
		}
		if (minindex == -1)
			return;
		now = minindex;
	}
}


void dfs(int id)
{
	if (id == 0)
	{
		path.push_back(id);
		int bring = 0, need = 0;
		for (int i = path.size() - 1; i >= 0;i--)
		{
			int id = path[i];
			if (dotweight[id] > 0)
			{
				bring += dotweight[id];
			}
			else
			{
				if (bring < abs(dotweight[id]))
				{
					need += abs(dotweight[id]) - bring;
					bring = 0;
				}
				else
				{
					bring = bring - abs(dotweight[id]);
				}
			}
		}

		if (need < minNeed)
		{
			minNeed = need;
			optPath = path;
			minBring = bring;
		}
		else if (need == minNeed && bring < minBring)
		{
			optPath = path;
			minBring = bring;
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
	scanf("%d %d %d %d", &capacity, &n, &sp, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dotweight[i]);
		dotweight[i] -= capacity / 2;
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &st1, &st2, &t);
		G[st1][st2] = t;
		G[st2][st1] = t;
	}

	djsk(0);
	dfs(sp);
	printf("%d ", minNeed);

	printf("%d", optPath[optPath.size()-1]);

	for (int i=optPath.size()-2;i>=0;i--)
	{
		printf("->%d", optPath[i]);
	}

	printf(" %d", minBring);
	system("pause");
}