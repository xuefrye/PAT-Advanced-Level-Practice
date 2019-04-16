/*
1106 Lowest Price in Supply Chain £¨25 ·Ö£©
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int maxn = 1e5 + 10;
int n;double p ,r;
int k, child;
bool visited[maxn] = { false };
vector<int> adj[maxn];
int minDeep = maxn;
int minCnt=0;

void dfs(int id,int deep)
{
	visited[id] = true;
	if (adj[id].size() == 0)
	{
		if (deep < minDeep)
		{
			minDeep = deep;
			minCnt = 1;
		}
		else if (deep == minDeep)
		{
			minCnt++;
		}
		return;
	}

	for (int i = 0; i < adj[id].size();i++)
	{
		if (visited[adj[id][i]] == false)
			dfs(adj[id][i], deep + 1);
	}
}

int main()
{
	cin >> n >> p >> r; r /= 100.0;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> child;
			adj[i].push_back(child);
		}
	}

	dfs(0,0);
	printf("%.4lf %d", p*pow(1 + r,minDeep), minCnt);
	system("pause");
}
