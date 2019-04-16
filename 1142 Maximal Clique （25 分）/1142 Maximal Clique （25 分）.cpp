/*
1142 Maximal Clique ��25 �֣�
2019��2��24��17:49:01
���Ѷ�,28����
ע���.
1.˼·Ҫ����
�ö���ṹ��ʾ���ܺͲ�����,Ҷ�ӽ���ǽ��.
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

int judge(vector<int> &v) //���� -1����clique 1����� 0��not max
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (G[v[i]][v[j]] == 0)
				return -1;
		}
	}

	for (int x = 1; x <= nv; x++) //�������нڵ�
	{
		if (findNum(v, x) == -1) //x����������
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
			if (exsit == true) //����һ������ʹ���clique���,��ô�������not max clique
				return 0;
		}
	}

	return 1; // �Ҳ��������κ�һ������ʹ���clique���,����max clique
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