#include<iostream>
#include<map>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, k, s1, s, s2;
const int maxn = 10100;
map<int, int> getLine;
vector<int> line[maxn];
vector<int> adj[maxn];
int visited[maxn] = { false };
int minDeep = 0x3fffffff;
int minLine = 0x3fffffff;
vector<int> path,optPath;

int transCnt(vector<int> &v)
{
	int cnt = -1, preLine = 0;
	for (int i = 1; i < v.size(); i++)
	{
		if (getLine[v[i] * 10000 + v[i - 1]] != preLine)
		{
			cnt++;
			preLine = getLine[v[i] * 10000 + v[i - 1]];
		}
	}
	return cnt;
}

void printLine(vector<int> &v)
{
	int start = v[0],preLine = 0;
	for (int i = 1; i < v.size(); i++)
	{
		if (getLine[v[i] * 10000 + v[i - 1]] != preLine)
		{
			if(preLine !=0)
				printf("Take Line#%d from %04d to %04d.\n", preLine, start, v[i - 1]);
			preLine = getLine[v[i] * 10000 + v[i - 1]];
			start = v[i - 1];
		}
	}
	printf("Take Line#%d from %04d to %04d.\n", preLine, start, v[v.size() - 1]);
}

void dfs(int s1, int s2, int deep)
{
	if (adj[s1].size() == 0 && s1 != s2)
		return;

	if (s1 == s2)
	{
		int lineCnt = transCnt(path);
		if (deep < minDeep)
		{
			optPath = path;
			minDeep = deep;
			minLine = lineCnt;
		}
		else if (deep == minDeep && lineCnt < minLine)
		{
			optPath = path;
			minLine = lineCnt;
		}
		return;
	}

	for (int i = 0; i < adj[s1].size(); i++)
	{
		if (visited[adj[s1][i]] == false)
		{
				path.push_back(adj[s1][i]);
				visited[adj[s1][i]] = true;
				dfs(adj[s1][i], s2, deep + 1);
				visited[adj[s1][i]] = false;
				path.pop_back();
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> s1;
			line[i].push_back(s1);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < line[i].size(); j++)
		{
			adj[line[i][j]].push_back(line[i][j - 1]);
			adj[line[i][j - 1]].push_back(line[i][j]);
			getLine[line[i][j] * 10000 + line[i][j - 1]] = getLine[line[i][j] + line[i][j - 1] * 10000] = i;
		}
	}

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> s1 >> s2;

		minDeep = 0x3fffffff;
		minLine = 0x3fffffff;
		fill(visited, visited + maxn, false);
		path.clear();
		path.push_back(s1);
		visited[s1] = true;
		dfs(s1, s2, 0);
		visited[s1] = false;
		int temp = transCnt(optPath);
		printf("%d\n", optPath.size()-1);
		printLine(optPath);
	}

	system("pause");
}

/*
4
7 1001 3212 1003 1204 1005 1306 7797
9 9988 2333 1204 2006 2005 2004 2003 2302 2001
13 3011 3812 3013 3001 1306 3003 2333 3066 3212 3008 2302 3010 3011
4 6666 8432 4011 1306
3
6666 2001
2004 3001
*/
