/*
1134 Vertex Cover （25 分）

注意点.
对边进行编号.
edge[nodeid].push(edgeid)用点来索引编号.说明这个点被边edgeid所连接.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int maxn = 1e4 + 10;
int n, m, k;
int e1, e2;
int nv, vi;
vector<int> edge[maxn];
vector<bool> exist(maxn);
vector<int> dot(maxn);
int d;
vector<int> h(maxn);

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &e1, &e2);
		edge[e1].push_back(i);
		edge[e2].push_back(i);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		bool flag = true;
		fill(h.begin(), h.end(), false);
		scanf("%d", &nv);
		for (int j = 0; j < nv; j++)
		{
			scanf("%d", &d);
			for (int x = 0; x < edge[d].size(); x++)
			{
				h[edge[d][x]] = true;
			}
		}

		for (int x = 0; x < m; x++)
		{
			if (h[x] == false)
			{
				flag = false;
				break;
			}
		}
	
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	system("pause");
}