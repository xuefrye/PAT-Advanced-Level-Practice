/*
1142 Maximal Clique （25 分）
2019年2月24日17:49:01
无难度,28分钟
注意点.
1.思路要清晰
用二叉结构表示可能和不可能,叶子结点是结果.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

const int maxn = 210;
int G[maxn][maxn] = { 0 };
vector<int> clique;

int nv, ne, m, k;
int e1, e2;
int c;

int findNum(vector<int> &v, int &num)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (num == v[i])
			return i;
	}
	return -1;
}

int judge(vector<int> &v) //返回 -1不是clique 1是最大 0是not max
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (G[v[i]][v[j]] == 0)
				return -1;
		}
	}

	for (int x = 1; x <= nv; x++) //遍历所有节点
	{
		if (findNum(v, x) == -1) //x不在序列中
		{
			bool exsit = true;
			for (int i = 0; i < v.size(); i++)
			{
				if (G[x][v[i]] == 0)
				{
					exsit = false;
					break;
				}
			}
			if (exsit == true) //存在一个点能使这个clique变大,那么这个就是not max clique
				return 0;
		}
	}

	return 1; // 找不到其他任何一个点能使这个clique变大,就是max clique
}

int main()
{
	scanf("%d %d", &nv, &ne);
	for (int i = 0; i < ne; i++)
	{
		scanf("%d %d", &e1, &e2);
		G[e1][e2] = G[e2][e1] = 1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &k);
		clique.clear();
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &c);
			clique.push_back(c);
		}

		int Case = judge(clique);

		if (Case == -1)
			printf("Not a Clique\n");
		else if (Case == 0)
			printf("Not Maximal\n");
		else if (Case == 1)
			printf("Yes\n");

	}
	system("pause");
}