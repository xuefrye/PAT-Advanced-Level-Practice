#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

const int maxn = 10000+10;
struct node
{
	int id;
	int deep;
};
vector<int> adj[maxn];
vector<int> line[maxn];
int visited[maxn] = { false };
int n, m,k, s1, s2;
int pre[maxn];
set<int> station;
set<int> huancheng;
set<int> lineSet[maxn];
vector<int> path;
map<int, int> luxian;
int bfs(int s, int e)
{
	visited[s] = false;
	queue<node> qnode;
	qnode.push(node({ s,0 }));
	while (!qnode.empty())
	{
		node temp = qnode.front(); qnode.pop();
		if (temp.id == e)
			return temp.deep;

		for (int i = 0; i < adj[temp.id].size(); i++)
		{
			if (visited[adj[temp.id][i]] == false)
			{
				pre[adj[temp.id][i]] = temp.id;
				visited[adj[temp.id][i]] = true;
				qnode.push(node({ adj[temp.id][i] ,temp.deep + 1 }));
			}
		}
	}
}

void findPath(int s,int e,vector<int> &v)
{
	path.clear();
	v.push_back(e);
	while (e != s)
	{
		v.push_back(pre[e]);
		e = pre[e];
	}
	reverse(path.begin(), path.end());
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
			station.insert(s1);
			lineSet[i].insert(s1);
			line[i].push_back(s1);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < line[i].size(); j++)
		{
			adj[line[i][j]].push_back(line[i][j-1]);
			adj[line[i][j - 1]].push_back(line[i][j]);
			luxian[line[i][j] * 10000 + line[i][j - 1]] = i;
			luxian[line[i][j]  + line[i][j - 1]* 10000] = i;
		}
	}

	for (auto each : station)
	{
		if (adj[each].size() > 2)
			huancheng.insert(each);
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> s1 >> s2;
		fill(visited, visited + maxn, false);
		int stopCnt = bfs(s1, s2);
		cout << stopCnt << endl;
		findPath(s1, s2, path);

		int start = s1, end = 0,lastLine=-1;
		for (int i = 0; i < path.size(); i++)
		{
			if (path[i] == s2 || huancheng.find(path[i]) != huancheng.end())
			{
				end = path[i];
				for (int x = 1; x <= n; x++)
				{
					if (lineSet[x].find(start) != lineSet[x].end() && lineSet[x].find(end) != lineSet[x].end() && x != lastLine)
					{
						lastLine = x;
						printf("Take Line#%d from %04d to %04d.\n", x, start, end);start = end;
						break;
					}
				}
			}
		}
		

	}

	system("pasue");
}
