/*
1021 Deepest Root £¨25 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1e4 + 10;
bool visited[maxn] = { false };
vector<int> adj[maxn];
vector<int> ans;


int n,t1,t2,maxdeep,thisdeep;

void dfs(int id,int deep)
{
	visited[id] = true;
	if (deep > maxdeep)
	{
		maxdeep = deep;
	}

	for (int i = 0; i < adj[id].size(); i++)
	{
		if (visited[adj[id][i]] == false)
		{
			dfs(adj[id][i], deep + 1);
		}
	}
}

void travel()
{
	int cnt = 0;
	maxdeep = 0;
	fill(visited, visited + maxn, false);

	for (int id = 1; id <= n; id++)
	{
		if (visited[id] == false)
		{
			dfs(id,1);
			cnt++;
		}
	}

	if (cnt != 1)
	{
		printf("Error: %d components\n", cnt); 
		return;
	}

	int totaldeep = 0;
	for (int id = 1; id <= n; id++)
	{
		maxdeep = 0;
		fill(visited, visited + maxn, false);
		dfs(id, 1);
		if (maxdeep > totaldeep)
		{
			totaldeep = maxdeep;
			ans.clear();
			ans.push_back(id);
		}
		else if (maxdeep == totaldeep)
		{
			ans.push_back(id);
		}
	}

	for (auto each : ans)
	{
		printf("%d\n", each);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &t1, &t2);
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}
	travel();
	system("pause");
}