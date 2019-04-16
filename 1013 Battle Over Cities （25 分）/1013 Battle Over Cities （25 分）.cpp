/*
1013 Battle Over Cities （25 分）
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1001;


bool visited[maxn] = { false };
vector<int> adj[maxn];
int n, m, k;
int c1, c2;
int need[maxn];

void dfs(int id)
{
	visited[id] = true;
	for (int i = 0; i < adj[id].size(); i++)
	{
		if(visited[adj[id][i]]==false)
			dfs(adj[id][i]);
	}
}


void travel()
{
	int cnt = 0; //连通图数
	for (int i = 1; i <= k; i++)
	{
		fill(visited, visited + maxn, false);
		visited[need[i]] = true;
		cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (visited[j] == false)
			{
				dfs(j);
				cnt++;
			}
		}
		printf("%d\n", cnt - 1);
	}
}


int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &c1, &c2);
		adj[c1].push_back(c2);
		adj[c2].push_back(c1);
	}

	for (int i = 1; i <= k; i++)
		scanf("%d", &need[i]);

	travel();

	system("pause");
}