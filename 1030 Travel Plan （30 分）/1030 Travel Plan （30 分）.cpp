/*
1030 Travel Plan ��30 �֣�
ע���:
1.���ݵ�ʱ������Ȩ֮��.����[i-1]д��[i]-1
������debug��Сʱ,��
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 2000;
const int inf = 0x3fffffff;
int dis[maxn][maxn] = { 0 };
int cost[maxn][maxn] = { 0 };
int visited[maxn] = { false };
int mdis[maxn]; //����㵽i������·��
int n, m, s, d;
int c1, c2, Dis, Cost; //����
vector<int> pre[maxn]; //��Žڵ�i��ǰ��.
vector<int> optPath, tempPath;
int optCost = inf, tempCost = 0;

void djsk(int start)
{
	fill(mdis, mdis + maxn, inf);
	int now = start;
	mdis[now] = 0;
	for (int id = 0; id < n; id++)
	{
		visited[now] = true;
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == false && dis[now][i] != 0)
			{
				if (mdis[now] + dis[now][i] < mdis[i])
				{
					mdis[i] = mdis[now] + dis[now][i];
					pre[i].clear();
					pre[i].push_back(now);
				}
				else if (mdis[now] + dis[now][i] == mdis[i])
				{
					pre[i].push_back(now);
				}
			}
		}

		int Min = inf, Mindex = -1;
		for (int j = 0; j < n; j++)
		{
			if (visited[j] == false && mdis[j] < Min)
			{
				Min = mdis[j];
				Mindex = j;
			}
		}
		now = Mindex;
	}
}


void dfs(int end)
{
	if (end == s) // ������ݾ͸ü���.
	{
		tempPath.push_back(end);
		tempCost = 0;
		for (int i = tempPath.size()-1; i>0; i--)
		{
			//��һ��debug��Сʱ,����[i-1]д��[i]-1
			tempCost += cost[tempPath[i]][tempPath[i-1]];
		}
		if (tempCost < optCost) //����·���ϵ�cost���ŵĻ�,����
		{
			optCost = tempCost;
			optPath = tempPath;
		}	
		tempPath.pop_back();
		return;
	}

	tempPath.push_back(end); //end�ĵ�i��ǰ������
	for (int i = 0; i < pre[end].size(); i++) //������������ǰ��dfs
	{
		dfs(pre[end][i]);
	}
	tempPath.pop_back(); //��Ӧfor��һ����push
}
int main()
{
	cin >> n >> m >> s >> d;
	for (int i = 0; i < m; i++)
	{
		cin >> c1 >> c2 >> Dis >> Cost;
		dis[c1][c2] = dis[c2][c1] = Dis;
		cost[c1][c2] = cost[c2][c1] = Cost;
	}

	djsk(s);
	dfs(d);

	for (int i = optPath.size() - 1; i >= 0; i--)
		cout << optPath[i] << " ";
	cout << mdis[d] << " " << optCost << endl;
	system("pause");
}
