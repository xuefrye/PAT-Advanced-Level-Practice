/*
1072 Gas Station £¨30 ·Ö£©

*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
const int maxn = 1e3 + 100;
const int inf = 0x3fffffff;
int G[maxn][maxn] = { 0 };
int n, m, k, ds;
string p1, p2;
int p1int,p2int,dist;
bool visited[maxn] = { false };
int dis[maxn];
double globleDis = 0;
int globleId=-1;
double globleAvg = inf;

void djsk(int start)
{
	fill(dis, dis + maxn, inf);
	fill(visited, visited + maxn, false);
	int now = start;
	dis[now] = 0;
	for (int i = 1; i <= n + m;i++)
	{
		visited[now] = true;
		for (int j = 1; j <= m + n; j++)
		{
			if (visited[j] == false && G[now][j] != 0 && dis[now] + G[now][j] < dis[j])
			{
				dis[j] = dis[now] + G[now][j];
			}
		}

		int minIndex = -1, minDis = inf;
		for (int j = 1; j <= m + n;j++)
		{
			if (visited[j] == false && dis[j] < minDis)
			{
				minIndex = j;
				minDis = dis[j];
			}
		}
		if (minIndex == -1)
			return;
		now = minIndex;
	}
}

void travel()
{
	for (int i = n + 1; i <= n + m; i++)
	{
		djsk(i);
		double minDis = inf, avg = 0;
		for(int j=1;j<=n;j++)
		{
			if (dis[j] > ds)
			{
				minDis = -1;
				break;
			}
			if(dis[j] < minDis)
			{
				minDis = dis[j];	
			}
			avg += dis[j] / (1.0*n);
		}

		if (minDis == -1) continue;
		if (minDis > globleDis)
		{
			globleDis = minDis; 
			globleAvg = avg;
			globleId = i;
		}
		else if (minDis == globleDis && avg < globleAvg)
		{
			globleAvg = avg;
			globleId = i;
		}
	}
	if (globleAvg == inf)
		printf("No Solution");
	else
		printf("G%d\n%.1f %.1f", globleId - n,globleDis,globleAvg);
}

int main()
{
	cin >> n >> m >> k >> ds;
	for (int i = 1; i <= k; i++)
	{
		cin >> p1 >> p2 >> dist;
		if (p1[0] == 'G') p1int = stoi(p1.substr(1)) + n;
			else p1int = stoi(p1);
		if (p2[0] == 'G') p2int = stoi(p2.substr(1)) + n;
			else p2int = stoi(p2);

		G[p1int][p2int] = dist;
		G[p2int][p1int] = dist;
	}

	travel();
	system("pause");

}