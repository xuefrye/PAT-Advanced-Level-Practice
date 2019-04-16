/*
1126 Eulerian Path £¨25 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

const int maxn = 5010;
vector<int> adj[maxn];
int degree[maxn] = { 0 };
int n,m, e1,e2;
bool visited[maxn] = { false };

void dfs(int id)
{
	visited[id] = true;
	for (int i = 0; i < adj[id].size(); i++)
	{
		if (visited[adj[id][i]] == false)
			dfs(adj[id][i]);
	}
}

int travel()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			dfs(i);
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &e1, &e2);
		degree[e1]++; degree[e2]++;
		adj[e1].push_back(e2); adj[e2].push_back(e1);
	}

	int first = true, isEluer = 1, oddcnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] % 2 == 1)
		{
			oddcnt++;
		}
		if (first)
		{
			printf("%d", degree[i]); first = false;
		}
		else printf(" %d", degree[i]);
	}

	int gcnt = travel();
	if (gcnt > 1)
	{
		printf("\nNon-Eulerian");
	}
	else if (oddcnt ==0)
	{
		printf("\nEulerian");
	}
	else if (oddcnt ==2)
	{
		printf("\nSemi-Eulerian");
	}
	else
		printf("\nNon-Eulerian");

	
	system("pause");
}