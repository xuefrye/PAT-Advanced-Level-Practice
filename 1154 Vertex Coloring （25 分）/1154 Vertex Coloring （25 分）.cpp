/*
1154 Vertex Coloring £¨25 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 1e4 + 10;
int n, m,k;
vector<int> adj[maxn];
int color[maxn];
int visited[maxn] = { false };
set<int> cCnt;
int cnt;
int flag = true;

struct node
{
	int a;
	int b;
	node() {};
	node(int x, int y)
	{
		a = x;
		b = y;
	}
}nodes[maxn];


void dfs(int id)
{
	visited[id] = true;
	for (int i = 0; i < adj[id].size(); i++)
	{
		if (color[id] == adj[id][i])
		{
			flag = false;
		}
		else
		{
			if (visited[adj[id][i]] == false && flag == true)
				dfs(adj[id][i]);
		}
	}
}


int main()
{
	freopen("test1154.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> nodes[i].a >> nodes[i].b;
	}

	cin >> k;
	for (int j = 0; j < k; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> color[i];
			cCnt.insert(color[i]);
		}
		cnt = cCnt.size(); 
		cCnt.clear();

		flag = true;
		for (int i = 0; i < m; i++)
		{
			if (color[nodes[i].a] == color[nodes[i].b])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			printf("%d-coloring\n", cnt);
		}
		else
		{
			printf("No\n");
		}
	}
	system("pause");
}