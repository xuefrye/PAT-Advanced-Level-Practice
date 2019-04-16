/*
1003 Emergency ��25 �֣�

ע���.
1.djsk���ڲ�ѭ��.
һ��Ҫ����n��
�ڲ�Ҫ������ѭ��,Ҳ��n��.
*/

#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1000;
const int inf = 0x0fffffff;

int G[maxn][maxn] = { 0 };//·��
int hand[maxn] = { 0 };//��Ա��
int maxhand[maxn] = { 0 }; //�����Ա��
int dis[maxn];
int pathnum[maxn] = { 0 };
bool visited[maxn] = { false };

int n, m, c1, c2, city1, city2, length;

void djsk(int start)
{
	fill(dis, dis + maxn, inf);
	dis[start] = 0;
	maxhand[start] = hand[start];
	pathnum[start] = 1;
	int now = start;
	for (int i = 0; i < n; i++)
	{
		visited[now] = true;
		for (int j = 0; j < n; j++) //ע��ѭ��,ѭ���Ƚ�ÿ����,������ֵ.һ��ʼ�������ѭ��ɾ��
		{
			if (visited[j] == false && G[now][j] != 0)
			{
				if (dis[now] + G[now][j] < dis[j])
				{
					dis[j] = dis[now] + G[now][j];
					maxhand[j] = maxhand[now] + hand[j];
					pathnum[j] = pathnum[now];
				}
				else if (dis[now] + G[now][j] == dis[j])
				{
					if (maxhand[now] + hand[j] > maxhand[j])
						maxhand[j] = maxhand[now] + hand[j];
					pathnum[j] += pathnum[now];
				}
			}
		}

		int mini = inf, mi = -1;
		for (int j = 0; j < n; j++)
		{
			if (visited[j] == false && dis[j] < mini)
			{
				mi = j;
				mini = dis[j];
			}
		}

		if (mi == -1) return;
		now = mi;
	}
}

int main()
{
	cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < n; i++)
	{
		cin >> hand[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> city1 >> city2 >> length;
		G[city1][city2] = length;
		G[city2][city1] = length;
	}

	djsk(c1);
	cout << pathnum[c2] << " " << maxhand[c2];
	system("pause");
}