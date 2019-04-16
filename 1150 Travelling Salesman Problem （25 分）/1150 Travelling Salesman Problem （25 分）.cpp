/*
1150 Travelling Salesman Problem ��25 �֣�
ע���
1.���������
 ���ǻ�·
 �ǻ�·��û�з������е�
 �ǻ�·�������е�һ��
 �ǻ�·������һ������ʴ���һ��
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 210;
int G[maxn][maxn] = { 0 };
int n, m, k;
int c, cn,c1, c2, dist;
vector<int>path;
int pathCnt = 1;
int visitCnt[maxn] = { 0 };
int optCnt, optSum = 0x3fffffff;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> c1 >> c2 >> dist;
		G[c1][c2] = G[c2][c1] = dist;
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> cn;
		path.clear();
		for (int j = 0; j < cn; j++)
		{
			cin >> c;
			path.push_back(c);
		}

		int sum = 0; fill(visitCnt, visitCnt + maxn, 0);
		for (int x = 1; x < path.size(); x++)
		{
			visitCnt[path[x]]++;
			if (G[path[x]][path[x - 1]] == 0)
			{
				sum = -1; //sum=-1˵�����ǻ�·
				break;
			}
			sum += G[path[x]][path[x - 1]];
		}

		//���涼�ǻ�·�����
		bool NOT = false, TS = false;
		for (int x = 1; x <= n; x++)
		{
			if (visitCnt[x] == 0)
			{
					NOT = true;
			}
			if (visitCnt[x] >= 2)
			{
					TS = true;
			}
		}

		if (sum == -1 || path[0] != path[path.size() - 1])
			printf("Path %d: NA (Not a TS cycle)\n", pathCnt++);
		else if (NOT)
		{
			printf("Path %d: %d (Not a TS cycle)\n", pathCnt++,sum);
		}
		else if (TS)
		{
			printf("Path %d: %d (TS cycle)\n", pathCnt++, sum);
			if (sum < optSum)
			{
				optSum = sum;
				optCnt = pathCnt - 1;
			}
		}
		else
		{
			printf("Path %d: %d (TS simple cycle)\n", pathCnt++, sum);
			if (sum < optSum)
			{
				optSum = sum;
				optCnt = pathCnt - 1;
			}
		}
	}
	printf("Shortest Dist(%d) = %d", optCnt, optSum);
	system("pause");
}