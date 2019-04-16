/*
1111 Online Map £¨30 ·Ö£©
*/

#include<iostream>
//#include<map>
#include<vector>
using namespace std;

const int maxn = 1000;
const int inf = 0x3fffffff;
vector<int> adj[maxn];
int t[maxn][maxn], d[maxn][maxn];
vector<int> timePath, disPath,minTimePath,minDisPath,path;
int mindisTime = inf, mintimDis = inf,
mintimTime = inf,mindisDis=inf;
int n, m, v1, v2, oneWay, l, t1,s,e;
bool visited[maxn] = { false };

void dfs(int s, int e,int tim, int dis)
{
	if (s == e)
	{
		if (tim < mintimTime)
		{
			mintimTime = tim;
			timePath = path;
			mintimDis = inf;
		}
		else if (tim == mintimTime && dis < mintimDis)
		{
			timePath = path;
			mintimDis = dis;
		}

		if (dis < mindisDis)
		{
			mindisDis = dis;
			disPath = path;
			mindisTime = inf;
		}
		else if (dis == mindisDis && tim < mindisTime)
		{
			disPath = path;
			mindisTime = tim;
		}
		return;
	}

	for (int i = 0; i < adj[s].size(); i++)
	{
		if (visited[adj[s][i]] == false)
		{
			path.push_back(adj[s][i]);
			visited[adj[s][i]] = true;
			dfs(adj[s][i], e, tim + t[s][adj[s][i]], dis + d[s][adj[s][i]]);
			visited[adj[s][i]] = false;
			path.pop_back();
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> oneWay >> l >> t1;
		t[v1][v2] = t[v2][v1] = t1;
		d[v1][v2] = d[v2][v1] = l;
		adj[v1].push_back(v2);
		if(!oneWay) adj[v2].push_back(v1);
	}

	cin >> s >> e;
	path.push_back(s);
	visited[s] = true;
	dfs(s, e,0,0);

	if (timePath == disPath)
	{
		printf("Distance = %d; Time = %d:", mindisDis, mintimTime);
		printf(" %d", timePath[0]);
		for(int i=1;i<timePath.size();i++)
			printf(" -> %d", timePath[i]);
	}
	else
	{
		printf("Distance = %d:", mindisDis);
		printf(" %d", disPath[0]);
		for (int i = 1; i < disPath.size(); i++)
			printf(" -> %d", disPath[i]);

		printf("\nTime = %d:", mintimTime);
		printf(" %d", timePath[0]);
		for (int i = 1; i < timePath.size(); i++)
			printf(" -> %d", timePath[i]);
	}
	system("pause");
}